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
vector<vector<int>>g;
vector<int>dist;
vector<int> vis;
vector<int> parent;

void solve() {
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    dist.assign(n+1,1e9);
    vis.assign(n+1,0);
    parent.assign(n+1,0);
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        for(auto v: g[node]){
            if(dist[v] > dist[node] + 1){
                dist[v] = dist[node] + 1;
                parent[v] = node;
                q.push(v);
            }
        }
    }
    if(vis[n]==0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    else{
        cout<<dist[n]+1<<"\n";
        vector<int> path;
        int curr = n;
        while(curr != 0){
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        for(auto x: path) cout<<x<<" ";
        cout<<"\n";
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long t; cin >> t; while(t--)
    solve();
}