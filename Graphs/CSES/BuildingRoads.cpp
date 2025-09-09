#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;

void dfs(int u, vector<int>& comp) {
    vis[u] = 1;
    comp.push_back(u);
    for (int v : g[u]) {
        if (!vis[v]) dfs(v, comp);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.assign(n + 1, {});
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> reps;  // representative node of each component

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> comp;
            dfs(i, comp);
            reps.push_back(i); // pick one node as representative
        }
    }

    int roads = reps.size() - 1;
    cout << roads << "\n";
    for (int i = 0; i < roads; i++) {
        cout << reps[i] << " " << reps[i+1] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
