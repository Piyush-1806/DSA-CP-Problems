// TopoOrderingBFS.cpp
// This code implements Kahn's algorithm for topological sorting of a Directed Acyclic Graph (DAG).
// It reads the number of nodes and edges, builds the graph, and performs Kahn's algorithm to find the topological order.
// The graph is represented using an adjacency list, and the algorithm uses an indegree array to track the number of incoming edges for each node.
// O(n + m) time complexity, where n is the number of nodes and m is the number of edges.
// O(n) space complexity for the graph and indegree array.
// This code can be used to find a valid linear ordering of tasks or dependencies in a directed acyclic graph (DAG).
// Input format: First line contains n (number of nodes)
// and m (number of edges), followed by m lines each containing two integers u and v indicating a directed edge from u to v.
// Output format: The topological order of the nodes.   
// Can also be used to detect cycles in a directed graph by checking if all nodes are included in the topological order. 

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
vector<int> indegree;

void kahnTopologicalSort(int vertices) {
    queue<int> q;

    for (int i = 0; i < vertices; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbor : g[current]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    g.resize(n);
    indegree.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
        indegree[r]++;
    }

    cout << "Topological Sorting Order: ";
    kahnTopologicalSort(n);

    return 0;
}