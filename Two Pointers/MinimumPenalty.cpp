// Problem: Minimum Penalty for a Shop
// Question - A shop is selling n items in a row. Each item is either a good item (represented by 0) or a bad item (represented by 1).
// The shop wants to minimize the penalty of the shop after closing. The penalty is calculated as follows:
// For each good item to the left of the closing time, the penalty increases by 1.
// For each bad item to the right of the closing time, the penalty increases by 1.
// The shop can close at any time from 0 to n (inclusive). Return the minimum penalty the shop can incur.
//Approach - We can solve this problem using the two-pointer technique. We will maintain a sliding window of size d and count the number of distinct bad items (1s) in that window. We will slide the window from the start of the array to the end, updating the count of distinct bad items as we go. The minimum count of distinct bad items in any window of size d will be our answer, as it represents the minimum penalty the shop can incur by closing at that point.

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, d;
    cin >> n >> d;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //head and tail
    int head = -1, tail = 0;

    //data structure for the question
    unordered_map<int,int> freq; // use map to handle large numbers safely
    int distinct = 0;

    //make the first window of size d
    while(head+1 < d){
        head++;
        if(freq[arr[head]] == 0) distinct++;
        freq[arr[head]]++;
    }

    int penalty = distinct;

    //slide the window
    while(head+1 < n){
        head++;
        if(freq[arr[head]] == 0) distinct++;
        freq[arr[head]]++;

        freq[arr[tail]]--;
        if(freq[arr[tail]] == 0) distinct--;
        tail++;

        penalty = min(penalty, distinct);
    }

    cout << penalty << "\n";
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    long long t;
    cin >> t;
    while(t--) 
        solve();
}
