//category - knapsack
// link - https://cses.fi/problemset/task/1633
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
const int mod = 1e9+7;

long long rec(int n, vector<int> &dp){
    //pruning
    if(n<0) return 0;
    //basecase
    if(n==0) return 1;
    //cache check
    if(dp[n]!=0) return dp[n];
    //transition
    long long ans = 0;
    for(int i=1; i<=6; i++){
        ans+=rec(n-i, dp);
        ans%=mod;
    }
    //save and return
    return dp[n] = ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0]=1;
    long long ans = rec(n, dp);
    cout<<ans%mod;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long t; cin >> t; while(t--)
    solve();
}