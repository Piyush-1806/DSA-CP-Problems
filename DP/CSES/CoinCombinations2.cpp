//Problem link - https://cses.fi/problemset/task/1635
//Don't use recursive approach because of large recursive overhead

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int c : coins) {
        for (int s = c; s <= x; s++) {
            dp[s] += dp[s - c];
            if (dp[s] >= MOD) dp[s] -= MOD;
        }
    }

    cout << dp[x] << "\n";
}