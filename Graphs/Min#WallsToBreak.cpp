// Min#WallsToBreak.cpp
// This problem involves finding the minimum number of walls to break in a grid to connect two points A and B.
// We can use a modified BFS approach to achieve this.  
// The BFS will treat walls as edges with a cost of 1, and free cells as edges with a cost of 0.    
// We will use a deque to implement a 0-1 BFS, where we push walls to the back and free cells to the front.
// The goal is to find the minimum cost path from A to B.
// Approach
// 1. Read the grid dimensions and the grid itself.
// 2. Initialize a distance matrix with INF.
// 3. Perform a BFS starting from point A, updating distances based on whether the next cell is a wall or not.
// 4. If we reach point B, print the distance;
// 5. If point B is unreachable, print -1.
// 6. Use a deque to efficiently manage the BFS queue.
// 7. Use a state structure to represent the current position in the grid.
// 8. Use a vector to store the grid and another vector for the distance matrix.
// 9. Use a pair to represent the coordinates of the points in the grid.    
// 10. Use a constant for infinity to represent unreachable cells.
// 11. Use a vector of pairs to represent the directions for movement in the grid.  
// 12. Use a function to check if a cell is inside the grid bounds.
// 13. Use a function to perform the BFS and update distances.
// 14. Use a function to solve the problem by reading input and calling the BFS function.


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <iomanip>
using namespace std;

const int INF = INT_MAX;
#define F first
#define S second

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
vector<string> arr;
using state = pair<int, int>;

vector<vector<int>> dist;

bool inside(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void bfs01(state st) {
    dist = vector<vector<int>>(n, vector<int>(m, INF));
    deque<state> dq;

    dist[st.F][st.S] = 0;
    dq.push_front(st);

    while (!dq.empty()) {
        state curr = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = curr.F + dx[i];
            int ny = curr.S + dy[i];
            if (!inside(nx, ny)) continue;

            int w = (arr[nx][ny] == '#'); // cost: 1 if wall, 0 otherwise
            if (dist[nx][ny] > dist[curr.F][curr.S] + w) {
                dist[nx][ny] = dist[curr.F][curr.S] + w;
                if (w == 0)
                    dq.push_front({nx, ny});
                else
                    dq.push_back({nx, ny});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    arr.resize(n);
    state st, en;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'A') st = {i, j};
            if (arr[i][j] == 'B') en = {i, j};
        }
    }

    bfs01(st);

    if (dist[en.F][en.S] == INF)
        cout << "-1\n";
    else
        cout << dist[en.F][en.S] << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }

    // Debug: print dist matrix
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == INF) cout << "X\t";
            else cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }
    */
}
