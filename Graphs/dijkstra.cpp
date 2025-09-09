// Dijkstra's Algorithm Implementation in C++
// This code implements Dijkstra's algorithm to find the shortest path in a weighted graph. 
// It reads the number of nodes and edges, builds the graph, and performs Dijkstra's algorithm starting from a source node.
// The graph is represented using an adjacency list with pairs indicating the adjacent node and the edge weight.
// The algorithm uses a priority queue to efficiently get the next node with the smallest distance.
// O(n log n + m) time complexity, where n is the number of nodes and m is the number of edges.
// O(n) space complexity for the graph, visited array, and distance array.
// This code can be used to find the shortest path in graphs with positive weights.


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

#define INF 1e9
#define F first
#define S second

int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
vector<int> visited;

void dijkstra(int sc) {
    visited.assign(n + 1, 0);
    dist.assign(n + 1, INF);

    // Min-heap (priority_queue with greater<>) -> stores {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[sc] = 0;
    pq.push({0, sc}); // distance 0, source node

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (visited[node]) continue; // Already processed with shortest distance
        visited[node] = 1;

        for (auto v : graph[node]) {
            int neigh = v.F;
            int cost = v.S;

            if (dist[neigh] > dist[node] + cost) {
                dist[neigh] = dist[node] + cost;
                pq.push({dist[neigh], neigh});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; // edge a-b with cost c
        graph[a].push_back({b, c});
        graph[b].push_back({a, c}); // undirected
    }

    int sc;
    cin >> sc; // source node

    dijkstra(sc);

    for (int i = 1; i <= n; i++) {
        cout << i << " " << dist[i] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
