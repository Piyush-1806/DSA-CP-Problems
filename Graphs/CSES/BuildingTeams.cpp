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
vector<int> color;
vector<int> vis;

void dfs(int node, int col, bool &bipartite) {
    vis[node] = 1;
    color[node] = col;
    for(auto v: g[node]){
        if(!vis[v]){
            dfs(v,3-col,bipartite);
        }
        else if(color[v] == col){
            bipartite = false;
            return;
        }
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    g.resize(n+1);
    color.assign(n+1, -1);
    vis.assign(n+1, 0);
    for(int i=0; i<m ; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool bipartite = true;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i,1,bipartite);
            if(!bipartite){
                cout<<"IMPOSSIBLE"<<"\n";
                return;
            }     
        }
    }
    for(int i=1; i<=n; i++){
        cout<<color[i]<<" ";
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long t; cin >> t; while(t--)
    solve();
}