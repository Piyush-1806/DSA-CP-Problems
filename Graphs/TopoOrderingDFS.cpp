// Topological Sorting using DFS in C++
// This code implements topological sorting of a directed acyclic graph (DAG) using Depth First Search (DFS).
// It reads the number of nodes and edges, builds the graph, and performs DFS to find the topological order.
// The graph is represented using an adjacency list.
// O(n + m) time complexity, where n is the number of nodes and m is the number of edges.
// O(n) space complexity for the graph and visited array.
// This code can be used to find a valid linear ordering of tasks or dependencies in a directed acyclic graph (DAG).
// Input format: First line contains n (number of nodes)
// and m (number of edges), followed by m lines each containing two integers u and v indicating a directed edge from u to v.
// Output format: The topological order of the nodes.   

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

vector<vector<int>> g;
vector<int> vis;
int n, m;
vector<int> topo;

void dfs_topo(int node)
{
    vis[node] = 1;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs_topo(v);
        }
    }
    topo.push_back(node);
}

int main()
{
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs_topo(i);
        }
    }
    reverse(topo.begin(), topo.end());

    for (int i = 0; i < topo.size(); i++)
    {
        cout << topo[i] << " ";
    }
}