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

//Time complexity : O(n * m * k) where n is the number of rows, m is the number of columns, and k is the maximum number of walls that can be broken.

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

const int INF = 1e9;
#define F first
#define S second

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m, k;
vector<string> arr;

struct State {
    int x, y, broken;
};

bool inside(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int bfs(pair<int,int> st, pair<int,int> en) {
    // dist[x][y][broken] = min steps to reach (x,y) with "broken" walls used
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k+1, INF)));
    deque<State> q;

    dist[st.F][st.S][0] = 0;
    q.push_back({st.F, st.S, 0});

    while(!q.empty()) {
        auto [x, y, broken] = q.front();
        q.pop_front();

        if (x == en.F && y == en.S) return dist[x][y][broken];

        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if(!inside(nx, ny)) continue;

            // Case 1: move into free cell
            if(arr[nx][ny] != '#') {
                if(dist[nx][ny][broken] > dist[x][y][broken] + 1) {
                    dist[nx][ny][broken] = dist[x][y][broken] + 1;
                    q.push_back({nx, ny, broken});
                }
            }

            // Case 2: break wall if allowed
            else if(broken < k) {
                if(dist[nx][ny][broken+1] > dist[x][y][broken] + 1) {
                    dist[nx][ny][broken+1] = dist[x][y][broken] + 1;
                    q.push_back({nx, ny, broken+1});
                }
            }
        }
    }

    return -1; // not reachable
}

void solve(){
    cin >> n >> m >> k;
    arr.resize(n);
    pair<int,int> st, en;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j] == 'A') st = {i,j};
            if(arr[i][j] == 'B') en = {i,j};
        }
    }

    int ans = bfs(st, en);
    if(ans == -1) cout << "NO\n";
    else cout << "YES\n" << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
