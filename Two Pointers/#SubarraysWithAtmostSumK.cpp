// Problem: Count of Subarrays with sum at most K
// Question - Given an array of positive integers and a positive integer K, find the number of contiguous subarrays where the sum of the elements is less than or equal to K.
// Approach - We can use the two-pointer technique to solve this problem efficiently. We will maintain two pointers, head and tail, to represent the current subarray. We will also maintain a variable sum to keep track of the sum of the elements in the current subarray. We will iterate through the array using the tail pointer and expand the head pointer as long as the sum of the elements in the current subarray is less than or equal to K. For each position of the tail pointer, we will add the number of valid subarrays ending at the tail pointer to our answer. If the sum exceeds K, we will shrink the window from the tail pointer until the sum is less than or equal to K again. This way, we can efficiently count the number of valid subarrays in O(n) time complexity.

#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

void solve(){
    int n;
    long long K;
    cin >> n >> K;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // head and tail
    int head = -1, tail = 0;
    // datastructure for the window
    long long sum = 0; 
    long long ans = 0;

    while(tail < n){
        // expand window while possible
        while(head + 1 < n && sum + arr[head + 1] <= K){
            head++;
            sum += arr[head];
        }

        // add all subarrays ending at head and starting from tail
        ans += (head - tail + 1);

        if(tail > head){
            // case where window is empty
            tail++;
            head = tail - 1;
        }
        else{
            // shrink window from tail
            sum -= arr[tail];
            tail++;
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) solve();
}
