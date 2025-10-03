// Problem: Given a string, we need to remove characters such that the subsequence "hard" is not present in the string. Each character has a removal cost, and we want to minimize the total removal cost.
// Link: https://maang.in/problems/Hard-Problem-182?resourceUrl=cs100-cp507-pl3410-rs182&returnUrl=%5B%22%2Fcourses%2FDynamic-Programming-Pro-100%3Ftab%3Dchapters%22%5D
// Approach: Use dynamic programming to track the minimum cost of removing characters while ensuring that the subsequence "hard" is not formed.
// Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;
string target = "hard";
int n;
string s;
vector<int> cost;
vector<vector<int>> dp;

int rec(int i, int j) {
    //Pruning
    if(j == 4) return INF;       // formed "hard"
    //Base Case
    if(i == n) return 0;         // end of string
    //Cache Check
    if(dp[i][j] != -1) return dp[i][j];
    //Transition
    int ans;
    if(s[i] == target[j]) {
        // Option 1: remove
        int removeCost = cost[i] + rec(i+1, j);
        // Option 2: keep and advance subsequence
        int keepCost   = rec(i+1, j+1);
        ans = min(removeCost, keepCost);
    } else {
        // Doesn't affect subsequence
        ans = rec(i+1, j);
    }
    return dp[i][j] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        cin >> n;
        cin >> s;
        cost.resize(n);
        for(int i=0; i<n; i++) cin >> cost[i];
        dp.assign(n, vector<int>(5, -1));
        cout << rec(0,0) << "\n";
    }
    return 0;
}
