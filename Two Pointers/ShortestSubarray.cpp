// Problem: Shortest Subarray with all distinct elements
// Question - Given an array of positive integers, find the length of the shortest contiguous subarray that contains all the distinct elements present in the entire array.
// Approach - We can use the two-pointer technique to solve this problem efficiently. First, we will determine the total number of distinct elements in the array using a set. Then, we will maintain two pointers, head and tail, to represent the current subarray. We will also maintain a frequency array to keep track of the count of each element in the current subarray and a variable distinct to keep track of the number of distinct elements. We will iterate through the array using the head pointer and include elements in the current subarray. Whenever the current subarray contains all distinct elements, we will try to shrink the window from the tail pointer while still maintaining all distinct elements. We will update the minimum length of such subarrays during this process.

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //find total distinct elements in the array
    set<int> s(arr.begin(), arr.end());
    int totalDistinct = s.size();

    //head and tail
    int head = 0, tail = 0;

    //data structure for the question
    vector<int> freq(1e5+1, 0);
    int distinct = 0;
    int ans = n; //maximum possible length

    while(head < n){
        //include current element
        if(freq[arr[head]] == 0) distinct++;
        freq[arr[head]]++;

        //try to shrink the window from left while keeping all distinct elements
        while(distinct == totalDistinct){
            ans = min(ans, head - tail + 1);
            freq[arr[tail]]--;
            if(freq[arr[tail]] == 0) distinct--;
            tail++;
        }
        head++;
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;
    while(t--) solve();
}