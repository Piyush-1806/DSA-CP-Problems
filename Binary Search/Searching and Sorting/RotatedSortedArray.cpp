//arr[mid]<arr[0]
#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int hi,lo,mid,ans;

int check(int mid){
    if(arr[mid]<arr[0]) return 1;
    return 0;
}
void solve(){
    int n;
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    hi = n-1;
    lo = 1;
    ans = 0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid)==1){
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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t;cin>> t ;while(t--) 
    solve();

}