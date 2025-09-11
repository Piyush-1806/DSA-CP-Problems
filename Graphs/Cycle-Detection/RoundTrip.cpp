//Question - Given an undirected graph, check if it contains a cycle or not.
//Approach - We can use DFS to detect a cycle in an undirected graph. We can keep track of the parent node of each node. If we encounter a visited node that is not the parent of the current node, then we have found a cycle.

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> vis;
vector<int> parent;
bool cycle;

void dfs(int node, int par){
    vis[node] = 1;
    parent[node] = par;
    for(auto v: g[node]){
        if(!vis[v]) dfs(v,node);
        else{
            if(v != parent[node]){
                cycle = true;
                return;
            }
        }
    }
}
void solve(){
    int n, m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    parent.assign(n+1,-1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cycle = false;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i,-1);
        }
        if(cycle==true){
            cout<<"YES"<<"\n"; return;
        }
    }
    cout<<"NO"<<"\n";
    return;

}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    //long long t;cin>> t ;while(t--) 
    solve();

}