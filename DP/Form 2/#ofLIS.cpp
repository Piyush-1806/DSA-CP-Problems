// Question - Number of Longest Increasing Subsequence


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> dp(n, 1);   // dp[i] = LIS length ending at i
    vector<int> cnt(n, 1);  // cnt[i] = number of LIS ending at i
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];      // reset count
                }
                else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];     // add more ways
                }
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLen) ans += cnt[i];
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
