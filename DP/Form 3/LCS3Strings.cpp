//Question - Given three strings s1, s2, and s3, find the length of the longest common subsequence among them.
// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
// It can be proven that there is always a unique longest common subsequence.
// If there is no common subsequence, return 0. 

#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;
string s1, s2, s3;

int rec(int i, int j, int k) {
    int x = s1.size();
    int y = s2.size();
    int z = s3.size();

    // pruning
    if(i == x || j == y || k == z) return 0;

    // cache check
    if(dp[i][j][k] != -1) return dp[i][j][k];

    // transition
    int ans = 0;
    if(s1[i] == s2[j] && s2[j] == s3[k]) {
        ans = 1 + rec(i+1, j+1, k+1);
    } else {
        ans = max({ rec(i+1, j, k),
                    rec(i, j+1, k),
                    rec(i, j, k+1) });
    }

    // save and return
    return dp[i][j][k] = ans;
}

void solve() {
    cin >> s1 >> s2 >> s3;
    int x = s1.size();
    int y = s2.size();
    int z = s3.size();

    dp = vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, -1)));

    cout << rec(0,0,0) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;
    while(t--) solve();
}
