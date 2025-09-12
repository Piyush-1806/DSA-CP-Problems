// Problem: Longest Distinct Subarray
// Question - Given an array of positive integers, find the length of the longest contiguous subarray where all the elements are distinct.
// Approach - We can use the two-pointer technique to solve this problem efficiently. We will maintain two pointers, head and tail, to represent the current subarray. We will also maintain a frequency map to keep track of the count of each element in the current subarray and a variable distinct to keep track of the number of distinct elements. We will iterate through the array using the tail pointer and expand the head pointer as long as all elements in the current subarray are distinct. For each position of the tail pointer, we will update the maximum length of the subarray. If we encounter a duplicate element, we will shrink the window from the tail pointer until all elements are distinct again. This way, we can efficiently find the length of the longest distinct subarray in O(n) time complexity.

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> arr;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    //head and tail
    int head = -1, tail = 0;
    //datastructure for the question
    map<int,int> mp;
    int distinct = 0;
    int length = 0;
    while(tail<n){
        while(head+1<n && (mp[arr[head+1]] == 0)){
            head++;
            mp[arr[head]]++;
        }
        length = max(length,head-tail+1);
        if(tail>head){
            //when window is empty
            tail++;
            head = tail-1;
        }
        else{
            //shrink the tail
            mp[arr[tail]]--;
            tail++;
        }
    }
    cout<<length<<"\n";
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t;cin>> t ;while(t--) 
    solve();

}