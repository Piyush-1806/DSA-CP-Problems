#include <bits/stdc++.h>

using namespace std;
int n,x;
vector<int> cost, pages;
vector<vector<int>>dp;

int rec(int i, int sum_remaining){
    //basecase
    if(i==n) return 0;
    //cache check
    if(dp[i][sum_remaining]!=-1) return dp[i][sum_remaining];
    //transition
    int ans = rec(i + 1, sum_remaining); // skip this book
    if (sum_remaining >= cost[i]) {
        ans = max(ans, pages[i] + rec(i + 1, sum_remaining - cost[i]));
    }
    //save and return
    return dp[i][sum_remaining] = ans;
}

void solve() {
    cin>>n>>x;
    cost.resize(n);
    pages.resize(n);
    dp.resize(n+1, vector<int>(x+1, -1));
    for(int i=0;i<n;i++) cin>>cost[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    int ans = rec(0,x);
    cout<<ans<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long t; cin >> t; while(t--)
    solve();
}