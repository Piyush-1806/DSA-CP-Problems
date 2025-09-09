// verticesInCycleInDAG.cpp
// This code counts the number of vertices in cycles in a Directed Acyclic Graph (DAG).
// It uses a depth-first search (DFS) approach to detect back edges and count the vertices involved in cycles.
// The graph is represented using an adjacency list, and the algorithm maintains a coloring scheme to track the state of each vertex.
// O(n + m) time complexity, where n is the number of vertices and m is the number of edges.
// O(n) space complexity for the graph, color array, parent array, and prefix sum array.
// This code can be used to identify vertices that are part of cycles in a DAG. 
// Note: The input graph must be a DAG, and the code assumes that the vertices are numbered from 1 to n.    
// Input format: First line contains n (number of vertices) and m (number of edges), followed by m lines each containing two integers u and v indicating a directed edge from u to v.   
// Output format: The number of vertices that are part of cycles in the DAG.

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


vector<int> col, parent, prefix, order;


void dfs(int node, int par, vector<vector<int>>& adj) {
    parent[node] = par;
    col[node] = 2;


    for (auto child : adj[node]) {
        if (col[child] == 1) {
            dfs(child, node, adj);
        } else if (col[child] == 2) {
            // back edge detected
            prefix[node]++;
            if (parent[child] != 0) // avoid accessing prefix[0]
                prefix[parent[child]]--;
        }
        // col[child] == 3 means already processed, do nothing
    }


    col[node] = 3;
    order.push_back(node);
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);


    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }


    col.resize(n + 1, 1);
    parent.resize(n + 1, 0);
    prefix.resize(n + 1, 0);


    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) {
            dfs(i, 0, adj);
        }
    }


    // reverse(order.begin(), order.end());
    for (auto it : order) {
        prefix[parent[it]] += prefix[it];
    }


    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (prefix[i] > 0) {
            cnt++;
        }
    }


    cout << cnt << endl;
}
