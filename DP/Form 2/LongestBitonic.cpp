// Question - Longest Bitonic Subsequence
// Link - https://cses.fi/problemset/task/1145
// A sequence is called bitonic if it is first increasing and then decreasing.
// Given an array of n integers, find the length of the longest bitonic subsequence.
// Approach - Find LIS from left and LIS from right (which is equivalent to LDS from left) and combine the results.
// Time Complexity - O(n^2)
// Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(vector<int>& arr, int n) {
    vector<int> lis(n, 1);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    return lis;
}

void findLongestBitonic() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    // LIS from left
    vector<int> lis = LIS(arr, n);

    // LIS from right (equivalent to LDS from left)
    reverse(arr.begin(), arr.end());
    vector<int> lds = LIS(arr, n);
    reverse(lds.begin(), lds.end());
    reverse(arr.begin(), arr.end());

    // Find max length
    int lbs = 0, index_of_lbs = -1;
    for(int i=0; i<n; i++){
        if(lis[i] + lds[i] - 1 > lbs){
            lbs = lis[i] + lds[i] - 1;
            index_of_lbs = i;
        }
    }

    cout << "longest bitonic subsequence length: " << lbs << "\n";
    cout << "index of longest bitonic subsequence: " << index_of_lbs 
         << " " << arr[index_of_lbs] << "\n";
}


