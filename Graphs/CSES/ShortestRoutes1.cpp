// Problem Link: https://cses.fi/problemset/task/1671
// Question - Given a directed weighted graph with n nodes and m edges, your task is to find the shortest distance from node 1 to all other nodes.
// Approach - We can use Dijkstra's algorithm to find the shortest distance from node 1 to all other nodes.
// Take care of - 1. In the priority queue, we need to store the distance and the node (in this order).
// 2. Since Priority queue in c++ is max heap by default, we need to push the negative of the distance to make it a min heap.


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}
