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
vector<vector<char>> grid;
vector<vector<int>> dist1;
vector<vector<int>> dist2;
vector<vector<int>> vis;
vector<vector<int>> vis2;
vector<vector<pair<int,int>>> parent;
using state = pair<int,int>;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
#define F first
#define S second

void solve() {
    int n, m;
    cin>>n>>m;
    grid.resize(n,vector<char>(m));
    dist1.assign(n,vector<int>(m,1e9));
    dist2.assign(n,vector<int>(m,1e9));
    vis.assign(n,vector<int>(m,0));
    vis2.assign(n,vector<int>(m,0));
    parent.assign(n,vector<state>(m,{-1,-1}));
    queue<state> q;
    queue<state> q2;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'M'){
                q.push({i,j});
                dist1[i][j] = 0;
            }
            if(grid[i][j]== 'A'){
                state startpoint = {i,j};
                parent[i][j] = {-1,-1};
                dist2[i][j] = 0;
                q2.push({i,j});
            }
        }
    }
    //multi source bfs for monsters
    while(!q.empty()){
        state curr = q.front();
        q.pop();
        if(vis[curr.F][curr.S]) continue;
        vis[curr.F][curr.S] = 1;
        for(int i=0; i<4; i++){
            int x = curr.S + dx[i];
            int y = curr.F + dy[i];
            if(x>=0 && x<m && y>=0 && y<n && grid[y][x] != '#' && dist1[y][x] > dist1[curr.F][curr.S]+1){
                dist1[y][x] = dist1[curr.F][curr.S]+1;
                q.push({y,x});
            }
        }
    }
    //bfs for player
    while(!q2.empty()){
        state curr = q2.front();
        q2.pop();
        if(vis2[curr.F][curr.S]) continue;
        vis2[curr.F][curr.S] = 1;
        for(int i=0; i<4; i++){
            int x = curr.S + dx[i];
            int y = curr.F + dy[i];
            if(x>=0 && x<m && y>=0 && y<n && grid[y][x] != '#' && dist2[y][x] > dist2[curr.F][curr.S]+1){
                dist2[y][x] = dist2[curr.F][curr.S]+1;
                parent[y][x] = {curr.F,curr.S};
                q2.push({y,x});
            }
        }
    }
    //check for escape
    state end;
    bool escape = false;
    for(int i=0; i<n; i++){
        if(dist2[i][0] < dist1[i][0]){
            escape = true;
            end = {i,0};
        }
        else if(dist2[i][m-1] < dist1[i][m-1]){
            escape = true;
            end = {i,m-1};
        }
    }
    for(int j=0; j<m; j++){
        if(dist2[0][j] < dist1[0][j]){
            escape = true;
            end = {0,j};
        }
        else if(dist2[n-1][j] < dist1[n-1][j]){
                escape = true;
                end = {n-1,j};
        }
    }
    if(!escape){
        cout<<"NO"<<"\n";
        return;
    }
    else{
        cout<<"YES"<<"\n";
        vector<char> path;
        state curr = end;
        while(curr.F != -1 || curr.S != -1){
            state p = parent[curr.F][curr.S];
            if(p.F == curr.F + 1 && p.S == curr.S) path.push_back('U');
            else if(p.F == curr.F - 1 && p.S == curr.S) path.push_back('D');
            else if(p.F == curr.F && p.S == curr.S + 1) path.push_back('L');
            else if(p.F == curr.F && p.S == curr.S - 1) path.push_back('R');
            curr = p;
        }
        reverse(path.begin(), path.end());
        cout<<path.size()<<"\n";
        for(auto x: path) cout<<x;
        cout<<"\n";
        return;
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long t; cin >> t; while(t--)
    solve();
}