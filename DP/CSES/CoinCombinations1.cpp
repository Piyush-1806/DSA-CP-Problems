// Problem: Coin Combinations I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1634
//Don't use recursive approach because of large recursive overhead


#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int c : coins) {
            if (i - c >= 0) {
                dp[i] = (dp[i]+dp[i-c]%mod)%mod;
            }
            if(i-c==0){
                dp[i]=(dp[i]+1)%mod;
            }
        }
    }

    cout << dp[x] << "\n";
}