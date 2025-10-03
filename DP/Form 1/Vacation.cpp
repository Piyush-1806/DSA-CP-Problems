// Atcoder - Vacation
// URL: https://atcoder.jp/contests/dp/tasks/dp_c


#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> A, B, C;
vector<vector<int>> dp;

int rec(int day, int last) {
    //basecase
    if(day == n) return 0;

    //cache check
    if(dp[day][last] != -1) return dp[day][last];

    //transition
    int ans = 0;
    if(last != 0) ans = max(ans, A[day] + rec(day+1, 0));
    if(last != 1) ans = max(ans, B[day] + rec(day+1, 1));
    if(last != 2) ans = max(ans, C[day] + rec(day+1, 2));

    //save and return
    return dp[day][last] = ans;
}

void solve() {
    cin >> n;
    A.resize(n);
    B.resize(n);
    C.resize(n);
    for(int i=0;i<n;i++) cin >> A[i] >> B[i] >> C[i];
    dp.assign(n, vector<int>(4, -1));
    int ans = rec(0, 3);
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
