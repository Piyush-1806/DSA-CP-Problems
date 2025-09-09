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

const int INF = INT_MAX;
#define F first
#define S second

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n,m;
vector<string> arr;
using state = pair<int, int>;

vector<vector<state>> parent;

vector<vector<int>> vis, dist;

bool inside(int x, int y) {
    if(x>=0 && x<n && y>=0 && y<m && arr[x][y]!='#') return 1;
    return 0;
}
vector<state> neighbours(state st) {
    vector<state> ans;
    for(int i=0;i<4;i++){
        state temp = {st.F + dx[i], st.S + dy[i]};
        if(inside(temp.F, temp.S)){
        ans.push_back(temp);    
        }
    }    
    return ans;
}

void bfs( state st){
    vis = vector<vector<int>> (n, vector<int>(m, 0));
    dist = vector<vector<int>> (n, vector<int>(m, INF));
    queue<state> q;

    dist[st.F][st.S] = 0;
    q.push(st);
    
    while(!q.empty()){
        state curr = q.front();
        q.pop();
        if(vis[curr.F][curr.S]) continue; //imp to check!!
        vis[curr.F][curr.S] = 1;
        //process the current state
        for(auto v: neighbours(curr)){
            //relaxing edge
            if(dist[v.F][v.S] > dist[curr.F][curr.S] + 1){
                dist[v.F][v.S] = dist[curr.F][curr.S] + 1;
                parent[v.F][v.S] = curr;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    arr.resize(n);
    parent = vector<vector<state>> (n, vector<state>(m,{-1,-1}));
    state st,en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j] == 'A'){
                st={i,j};
            }else if(arr[i][j] == 'B'){
                en={i,j};
            }
        }
    }
    
    bfs(st);
    
    if(dist[en.F][en.S] == INF) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << dist[en.F][en.S] << "\n";
        vector<char> path;
        state cur = en;
        while(cur != st) {
            state p = parent[cur.F][cur.S];
            if(p.F == cur.F) {
                if(p.S + 1 == cur.S) path.push_back('R');
                else path.push_back('L');
        }   else {
                if(p.F + 1 == cur.F) path.push_back('D');
                else path.push_back('U');
            }
            cur = p;
        }
        reverse(path.begin(), path.end());
        for(char c : path) cout << c;
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1; // Number of test cases
    // cin >> t; // Uncomment if multiple test cases are needed
    while(t--) {
        solve();
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dist[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
}