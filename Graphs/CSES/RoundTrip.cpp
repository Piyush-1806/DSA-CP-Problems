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

vector<vector<int>> g;
vector<int> parent, vis;
int start_node, end_node;

bool dfs(int node, int par) {
    vis[node] = 1;
    parent[node] = par;
    for (auto v : g[node]) {
        if (v == par) continue;
        if (!vis[v]) {
            if (dfs(v, node)) return true;
        } else {
            start_node = v;
            end_node = node;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.assign(n + 1, {});
    parent.assign(n + 1, -1);
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, -1)) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> path;
        path.push_back(start_node);
        for (int cur = end_node; cur != start_node; cur = parent[cur]) {
            path.push_back(cur);
        }
        path.push_back(start_node);
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (auto x : path) cout << x << " ";
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
