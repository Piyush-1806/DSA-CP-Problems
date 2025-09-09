// Graphs/EasyGraphQueries.cpp
// This code implements a solution to handle queries on an undirected graph.
// It uses Depth First Search (DFS) to find connected components and answer queries about them.
// The graph is represented using an adjacency list.
// It supports two types of queries:
// 1. Get the size of the component containing a given node.
// 2. Check if two nodes belong to the same component.  
// O(n + m) time complexity for building the graph and O(n) space complexity for storing the graph and visited nodes.

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

vector<vector<int>> g;       // adjacency list
vector<int> visited;         // visited array
vector<int> colourArr;       // stores component colour for each node
vector<int> sizeArr;         // sizeArr[colour] = size of component

int dfs(int node, int colour) {
    visited[node] = 1;
    colourArr[node] = colour;
    int sze = 1;

    for (auto v : g[node]) {
        if (!visited[v]) {
            sze += dfs(v, colour);
        }
    }
    return sze;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    g.resize(n + 1);
    visited.assign(n + 1, 0);
    colourArr.assign(n + 1, 0);
    sizeArr.assign(n + 1, 0);  // max n components possible

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int colour = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            colour++;
            int size = dfs(i, colour);
            sizeArr[colour] = size;
        }
    }

    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int X;
            cin >> X;
            cout << sizeArr[colourArr[X]] << "\n";
        }
        else if (cmd == 2) {
            int X, Y;
            cin >> X >> Y;
            if (colourArr[X] == colourArr[Y]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
