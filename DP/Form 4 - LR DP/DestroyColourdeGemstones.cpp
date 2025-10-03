// Question - Destroy Colourde Gemstones
// Link - https://maang.in/problems/Destroy-Coloured-Gemstones-179?resourceUrl=cs99-cp522-pl3616-rs179&returnUrl=%5B%22%2Fcourses%2FPremium-Day-Wise-Course-99%3Ftab%3Dchapters%22%5D
// Given a sequence of n coloured gemstones, where each gemstone is represented by an integer denoting its colour.
// You can perform the following operation any number of times (including zero):
// Choose a contiguous subsequence of gemstones where the first and last gemstones have the same colour, and remove the entire subsequence from the sequence.
// Your task is to determine the minimum number of operations required to remove all gemstones from the sequence.
// Note: You can remove a single gemstone by choosing a subsequence of length 1.

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<vector<int>> dp;

int rec(int l, int r){
    // pruning
    if(l > r) return 0;
    // base case
    if(l == r) return 1;
    if(l + 1 == r) return (arr[l] == arr[r]) ? 1 : 2;
    // cache check
    if(dp[l][r] != -1) return dp[l][r];
    // transition
    int ans = 1e9;

    // case 1: ends match -> can remove them together as part of the same operation
    if(arr[l] == arr[r]){
        ans = min(ans, rec(l+1, r-1));
    }

    // case 2: split into two parts
    for(int mid = l; mid < r; mid++){
        ans = min(ans, rec(l, mid) + rec(mid+1, r));
    }

    // save and return
    return dp[l][r] = ans;
}

void solve(){
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    cout << rec(0, n-1) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}