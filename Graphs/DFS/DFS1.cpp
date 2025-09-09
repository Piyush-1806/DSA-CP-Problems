// Graphs/DFS1.cpp
//General Depth First Search (DFS) implementation in C++
// This code implements a simple DFS algorithm on an undirected graph.
// It reads the number of nodes and edges, builds the graph, and performs DFS starting from node 1.
// The graph is represented using an adjacency list.
// It also uses a vector to keep track of visited nodes.
// The DFS function marks nodes as visited and recursively visits all adjacent nodes.
// The main function initializes the graph and calls the solve function to execute the DFS.
// This code is suitable for competitive programming and can be used as a template for DFS problems.

// O(n + 2m) ~ O(n+m) time complexity, where n is the number of nodes and m is the number of edges.
// O(n) space complexity for the adjacency list and visited array.

//This code can be used to find # of connected components.
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
#define int long long
vector<vector<int>> g(100100); // Array of vector ints
vector<int> visited;

void dfs(int node) {
    visited[node] = 1; // Mark the current node as visited

    for(auto v : g[node]) {
        if(!visited[v]) { // If the adjacent node is not visited
            dfs(v); // Recur for the adjacent node
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m; // Read number of nodes and edges
    g.resize(n + 1); // Resize graph to hold n nodes
    visited.resize(n+1); // Resize visited array
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // Assuming 1-based indexing for nodes
        // Add edge to the graph
        g[a].push_back(b);
        // Add reverse edge for undirected graph
        g[b].push_back(a);
    }
    int connectedComponents = 0; // Counter for connected components
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) { // If the node is not visited
            connectedComponents++; // Increment connected components count
            dfs(i); // Perform DFS from this node  
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long t; cin >> t; while(t--)
    solve();
}

//This code can be tweaked to colour the graph.