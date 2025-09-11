//Question - In a given grid, each cell can have one of three values:
// the value 0 representing an empty cell,
// the value 1 representing a healthy person,
// the value 2 representing an infected person.
// Every minute, any healthy person that is 4-directionally adjacent to an infected person becomes infected.
// Return the minimum number of minutes that must elapse until no cell has a healthy person.
// If this is impossible, return -1.
//Approach - We can use multi-source BFS to solve this problem. We can start from all the infected people and then spread the infection to the healthy people.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    queue<pair<pair<int,int>, int>> q;

    int healthy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
            } else if (grid[i][j] == 1) {
                healthy++;
            }
        }
    }

    int maxTime = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [cell, time] = q.front(); q.pop();
        int x = cell.first, y = cell.second;
        maxTime = max(maxTime, time);

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                healthy--;
                q.push({{nx, ny}, time + 1});
            }
        }
    }

    if (healthy > 0) cout << -1 << "\n";
    else cout << maxTime << "\n";

    return 0;
}
