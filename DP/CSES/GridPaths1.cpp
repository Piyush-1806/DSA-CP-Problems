// Question - https://cses.fi/problemset/task/1633

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
vector<vector<char>> grid;
vector<vector<int>> dp;
const int mod = 1e9+7;
int dx[2] = {1,0};
int dy[2] = {0,1};
#define F first
#define S second
using state =  pair<int,int>;
int n;

int rec(state curr){
    //pruning
    if(curr.F<0 || curr.F>=n || curr.S<0 || curr.S>=n || grid[curr.F][curr.S]=='*') return 0;
    //basecase
    if(curr.F == n-1 && curr.S == n-1) return 1;
    //cache check
    if(dp[curr.F][curr.S]!=-1) return dp[curr.F][curr.S];
    //transition
    int ways = 0;
    for(int i=0; i<2; i++){
        state next = {curr.F+dy[i], curr.S+dx[i]};
        ways = (ways + rec(next)%mod)%mod;
    }
    //save and return
    return dp[curr.F][curr.S] = ways;
}

void solve() {
    cin>>n;
    grid.resize(n, vector<char>(n));
    dp.assign(n, vector<int>(n,-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    state start = {0,0};
    int ans = rec(start);
    cout<<ans%mod<<"\n";

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long t; cin >> t; while(t--)
    solve();
}