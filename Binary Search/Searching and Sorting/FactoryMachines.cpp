//Binary Search - Countribution
//Search Space -
// Max time = max(arr) * t
// Min time = 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <iomanip>

using namespace std;
#define int long long

int check(int mid, vector<int>& arr, int t){
    int total = 0;
    for(int i=0; i<arr.size(); i++){
        total += mid/arr[i];
        if(total>=t) return 1;
    }
    return 0;
}

void solve() {
    int n,t;
    cin>>n>>t;
    vector<int> arr(n);
    int maxi;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]>maxi) maxi = arr[i];
    }
    int hi = maxi * t;
    int lo = 0;
    int ans = hi;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid,arr,t)){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long t; cin >> t; while(t--)
    solve();
}