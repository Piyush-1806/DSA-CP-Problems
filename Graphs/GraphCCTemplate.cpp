// GraphCCTemplate.cpp
// This code implements a template for working with connected components in a graph.
// It reads the number of nodes and edges, builds the graph, and performs DFS to find
// connected components. It also handles queries to check if two nodes are in the same component.
// O(n + m) time complexity, where n is the number of nodes and m is the number of edges.
// O(n) space complexity for the graph, visited array, and component size array.
// This code can be used as a template for similar problems involving connected components in graphs.   
// Input format: First line contains n (number of nodes) and m (number of edges), followed by m lines each containing two integers u and v indicating an edge between u and v.  
// Output format: The number of connected components and the size of each component.

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

// Number of nodes and edges
int n, m;

// Adjacency list representation of the graph
vector<vector<int>> g;

// Visited array to mark visited nodes during DFS
vector<int> vis;

// Stores the component number for each node
vector<int> comp_num;

// Stores the size of each connected component (index = component number)
vector<int> comp_size;

/**
 * Depth First Search to traverse a connected component
 * @param node    Current node being visited
 * @param comp_no Current connected component number
 */
void dfs(int node, int comp_no) {
    vis[node] = 1;               // Mark current node as visited
    comp_num[node] = comp_no;    // Assign the component number to this node
    comp_size[comp_no]++;        // Increase the size of the current component
    
    // Visit all unvisited neighbors
    for (auto v : g[node]) {
        if (!vis[v]) {
            dfs(v, comp_no);
        }
    }
}

/**
 * Solves the connected component queries problem.
 * Input format:
 *  n m
 *  m edges (u, v)
 *  q (number of queries)
 *  q queries (a, b) asking if a and b are in the same connected component
 */
void solve() {
    cin >> n >> m;
    
    // Initialize graph and helper arrays
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    comp_num.resize(n + 1, 0);
    comp_size.resize(n + 1, 0);
    
    // Read edges and build the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    // Find connected components using DFS
    int comp_no = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            comp_no++;           // New component found
            dfs(i, comp_no);     // Explore this component
        }
    }
    
    // Answer queries
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        // If both nodes have the same component number → connected
        if (comp_num[a] == comp_num[b]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    // Debugging: Uncomment to print extra info
    // for (int i = 1; i <= n; i++) {
    //     cout << comp_size[comp_num[i]] << endl; // Size of each node's component
    // }
    // for (auto v : comp_num) cout << v << " ";
    // cout << endl;
    // for (auto v : comp_size) cout << v << " ";
    // cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    while (t--) {
        solve();
    }
}
