// Problem: Removing Digits
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int rec(int num) {
    // basecase
    if (num == 0) return 0;

    // cache check
    if (dp[num] != -1) return dp[num];

    int ans = INT_MAX;
    int temp = num;
    // transition: try removing each non-zero digit
    while (temp > 0) {
        int digit = temp % 10;
        temp /= 10;
        if (digit != 0 && num - digit >= 0) {
            ans = min(ans, 1 + rec(num - digit));
        }
    }

    return dp[num] = ans;
}

void solve() {
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    cout << rec(n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
