//Question - You are given a 2D grid of characters, where each cell is either empty ('.'), a wall ('#'), a monster ('M'), or the player ('A'). The player can move to any adjacent empty cell (up, down, left, right) and wants to reach any boundary cell of the grid. Monsters also move to adjacent empty cells but can move simultaneously with the player. If a monster reaches a cell before or at the same time as the player, the player cannot move there. Determine if the player can escape to the boundary and if so, find the shortest path.
//Approach - We can use multi-source BFS to find the shortest time for each cell to be reached by a monster. Then, we can use BFS for the player to find the shortest path to the boundary, ensuring that the player only moves to cells that the monsters reach later. 

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<string> grid;
vector<vector<int>> monsterDist, playerDist;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

struct State{
    int x,y;
};

bool inside(int x, int y) {
    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#') return 1;
    return 0;
}

void multiSourceBFS(vector<State>& monsters) {
    queue<State> q;
    for (auto mon : monsters) {
        monsterDist[mon.x][mon.y] = 0;
        q.push(mon);
    }

    while (!q.empty()) {
        State curr = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i], ny = curr.y + dy[i];
            if (inside(nx, ny) && monsterDist[nx][ny] > monsterDist[curr.x][curr.y] + 1) {
                monsterDist[nx][ny] = monsterDist[curr.x][curr.y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool playerBFS(State start) {
    queue<State> q;
    playerDist[start.x][start.y] = 0;
    q.push(start);

    while (!q.empty()) {
        State curr = q.front(); q.pop();

        // If player reaches boundary safely → escape
        if (curr.x == 0 || curr.y == 0 || curr.x == n - 1 || curr.y == m - 1) {
            cout << "YES\n" << playerDist[curr.x][curr.y] << "\n";
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i], ny = curr.y + dy[i];
            if (inside(nx, ny) && playerDist[nx][ny] == INF) {
                int nextTime = playerDist[curr.x][curr.y] + 1;

                // player can move only if monster arrives later
                if (nextTime < monsterDist[nx][ny]) {
                    playerDist[nx][ny] = nextTime;
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    monsterDist.assign(n, vector<int>(m, INF));
    playerDist.assign(n, vector<int>(m, INF));

    State player;
    vector<State> monsters;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                player = {i, j};
            } else if (grid[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }

    // Step 1: Multi-source BFS for monsters
    multiSourceBFS(monsters);

    // Step 2: BFS for player
    if (!playerBFS(player)) {
        cout << "NO\n";
    }
    return 0;
}
