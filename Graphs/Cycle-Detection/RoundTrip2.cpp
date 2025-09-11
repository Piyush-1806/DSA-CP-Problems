//Question - Given a directed graph, check if it contains a cycle or not.
//Approach - We can use DFS to detect a cycle in a directed graph. We can keep track of the nodes in the current path using a color array. If we encounter a node that is already in the current path, then we have found a cycle.  


#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> vis;
vector<int>color;
bool cycle;

void dfs(int node){
    color[node] = 2;
    vis[node] = 1;
    for(auto v: g[node]){
        if(!vis[v]){
            dfs(v);
        }
        else{
            if (color[v] == 2){
                cycle = true;
                return;
            }
        }
    }
    color[node] = 3;
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.clear();
    vis.clear();
    color.clear();
    g.resize(n+1);
    vis.assign(n+1,0);
    color.assign(n+1,1);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    cycle = false;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
            if(cycle == true){
                cout<<"Yes"<<endl;
                return;
            }
        }
    }
    cout<<"No"<<endl;
    return;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t;cin>> t ;while(t--) 
    solve();

}