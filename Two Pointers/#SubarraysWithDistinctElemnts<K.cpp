// Problem: Count of Subarrays with at most K distinct elements
// Question - Given an array of positive integers and a positive integer K, find the number of contiguous subarrays where the number of distinct elements is less than or equal to K.
// Approach - We can use the two-pointer technique to solve this problem efficiently. We will maintain two pointers, head and tail, to represent the current subarray. We will also maintain a frequency array to keep track of the count of each element in the current subarray and a variable distinct to keep track of the number of distinct elements. We will iterate through the array using the tail pointer and expand the head pointer as long as the number of distinct elements in the current subarray is less than or equal to K. For each position of the tail pointer, we will add the number of valid subarrays ending at the tail pointer to our answer. If the number of distinct elements exceeds K, we will shrink the window from the tail pointer until the number of distinct elements is less than or equal to K again. This way, we can efficiently count the number of valid subarrays in O(n) time complexity.
// We will use a frequency array of size 1e6+1 to accommodate the constraints of the problem.

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> arr;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    //head and tail
    int head = -1, tail = 0;
    //data structure for the window
    vector<int>freq;
    freq.assign(1e6+1,0);
    int distinct = 0;
    long long ans = 0;
    while(tail<n){
        while(head+1 < n && (distinct < k || freq[arr[head+1]] >= 1)){
            //increase the window as much as possible
            head++;
            if(freq[arr[head]]==0) distinct++;
            freq[arr[head]]++;
        }
        ans += head-tail+1;
        if(tail>head){
            // when window is empty
            tail++;
            head = tail-1;
        }
        else{
            //move tail forward and make the changes
            freq[arr[tail]]--;
            if(freq[arr[tail]] == 0) distinct--;
            tail++;
        }
    }
    cout<<ans<<"\n";
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t;cin>> t ;while(t--) 
    solve();

}