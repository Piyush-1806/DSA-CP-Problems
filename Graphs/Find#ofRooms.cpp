// Graphs/Find#ofRooms.cpp
// This code implements a solution to count the number of rooms in a grid represented by '.' (empty space) and '#' (walls).
// It uses Depth First Search (DFS) to explore connected components in the grid.
// The grid is represented as a vector of strings, and the DFS function marks visited cells.
// The main function initializes the grid, calls DFS for each unvisited cell, and counts the number of rooms.
// The time complexity is O(n * m) where n is the number of rows and m is the number of columns in the grid.
// The space complexity is O(n * m) for the visited array.


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

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < n &&
           y >= 0 && y < m &&
           grid[x][y] == '.' &&
           !visited[x][y];
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (isValid(nx, ny)) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int roomCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j);
                roomCount++;
            }
        }
    }

    cout << roomCount << "\n";
    return 0;
}