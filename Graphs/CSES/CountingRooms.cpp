#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> visited;
vector<vector<char>> graph;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n;
int m;

bool feasible(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m) return 1;
    return 0;
}

void dfs(int i, int j){
    visited[i][j] = 1;
    for(int k=0; k<4; k++){
        if(feasible(i+dy[k],j+dx[k])){
            if(graph[i+dy[k]][j+dx[k]] == '.' &&
               visited[i+dy[k]][j+dx[k]]==0){
                dfs(i+dy[k],j+dx[k]);
               }
        }
    }
}
void solve(){
    cin>>n>>m;
    visited = vector<vector<int>> (n,vector<int>(m,0));
    graph = vector<vector<char>>(n, vector<char>(m));
    //vector<vector<char>> map;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>graph[i][j];
        }
    }
    int num_comp = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(graph[i][j]!='#' && visited[i][j]==0){
                num_comp++;
                dfs(i,j);
            }
        }
    }
    cout<<num_comp<<"\n";
}
signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}