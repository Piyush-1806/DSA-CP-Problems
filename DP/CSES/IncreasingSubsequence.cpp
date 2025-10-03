// LIS in O(n log n) time complexity
// URL: https://cses.fi/problemset/task/1145

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
int n;

void solve() {
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> lis;
    for(int i=0; i<n; i++){
        if(lis.empty() || arr[i]>lis.back()){
            lis.push_back(arr[i]);
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
    }
    cout<<lis.size()<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // long long t; cin >> t; while(t--)
    solve();
}