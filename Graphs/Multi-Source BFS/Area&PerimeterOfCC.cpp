//Question - You are given an n x n grid filled with '.' and '#' characters. A connected component is defined as a group of '#' characters connected 4-directionally (up, down, left, right). The area of a connected component is the number of '#' characters in it, and the perimeter is the number of edges that are adjacent to '.' characters or the boundary of the grid. Your task is to find the connected component with the largest area. If there are multiple components with the same largest area, choose the one with the smallest perimeter. Output the area and perimeter of this component.
//Approach - We can use BFS to explore each connected component of '#' characters, calculating both its area and perimeter as we go. We maintain a record of the largest area found and the smallest perimeter for that area.


#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> grid;
vector<vector<int>> vis;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<int,int> bfs(int sx, int sy) {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;

    int area = 0, perimeter = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        area++;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == '.') {
                perimeter++; // boundary or empty
            } else if (!vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return {area, perimeter};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vis.assign(n, vector<int>(n, 0));

    int bestArea = 0, bestPerimeter = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#' && !vis[i][j]) {
                auto [area, per] = bfs(i, j);
                if (area > bestArea) {
                    bestArea = area;
                    bestPerimeter = per;
                } else if (area == bestArea && per < bestPerimeter) {
                    bestPerimeter = per;
                }
            }
        }
    }

    cout << bestArea << " " << bestPerimeter << "\n";
    return 0;
}
