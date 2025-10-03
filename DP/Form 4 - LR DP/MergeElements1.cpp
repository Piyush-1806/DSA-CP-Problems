// Question - Merge Elements
// Link - https://maang.in/problems/Merge-Elements-1-161?resourceUrl=cs99-cp522-pl3615-rs161&returnUrl=%5B%22%2Fcourses%2FPremium-Day-Wise-Course-99%3Ftab%3Dchapters%22%5D
// You are given an array of n elements. You can perform the following operation on the array:
// Choose two adjacent elements and merge them. The cost of this operation is equal to the sum of the two elements.
// After merging, the two elements will be replaced by a single element whose value is equal to the sum of the two elements.
// Your task is to find the minimum cost to merge all elements of the array into a single element.
// Form 4 - LR DP
// Further optimized using prefix sum
// Time Complexity - O(n^3) -> O(n^2)
// Space Complexity - O(n^2)

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
vector<vector<int>> dp;

int rec(int l, int r){
    //pruning -> not required
    //base case
    if(l==r) return 0;
    //cache check
    if(dp[l][r] != -1) return dp[l][r];
    //transition
    int ans = 1e9;
    int tot = 0;
    int sum = 0;
    for(int mid=l; mid<=r; mid++){
        tot += arr[mid];
    }
    for(int mid=l; mid<r; mid++){
        sum += arr[mid];
        ans = min(ans, rec(l,mid)+rec(mid+1,r)+(sum%100)*((tot-sum)%100));
    }
    //save and return
    return dp[l][r] = ans;
}

void solve(){
    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    dp = vector<vector<int>>(n, vector<int>(n,-1));
    int ans = rec(0,n-1);
    cout<<ans<<"\n";
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    //long long t;cin>> t ;while(t--) 
    solve();

}