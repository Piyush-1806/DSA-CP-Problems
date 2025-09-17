// Problem: Good Numbers
// Question - You are given n ranges and an integer k. A number is called good if it is present in at least k ranges. You have to answer q queries of the form l, r. For each query, you have to print the count of good numbers in the range l to r (both inclusive).
// Input Format - The first line contains three integers n, k and q, denoting the number of ranges, the integer k and the number of queries. The next n lines contain two integers l and r, denoting the ranges. The next q lines contain two integers l and r, denoting the range for which you have to find the count of good numbers.
// Approach - We will use the technique of partial sums to build an array where each index represents how many ranges cover that index. We will then convert this array into a binary array where each index is 1 if it is a good number (covered by at least k ranges) and 0 otherwise. Finally, we will build a prefix sum array on this binary array to answer the queries in O(1) time.


#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, q;
  cin >> n >> k >> q;
  int arr[N];  // note that N and n are different.
  for (int i = 0; i < N; i++) arr[i] = 0;

  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    // use the technique of Partial sum to build the value at each index.
    arr[l]++;
    arr[r + 1]--;
  }
  // finally build the prefix sum.
  for (int i = 1; i < N; i++) arr[i] += arr[i - 1];

  // keep the values 1 where values >=k or else 0.
  for (int i = 1; i < N; i++) arr[i] = (arr[i] >= k);

  // now to answer query in O(1), we will build prefix sum on this 0/1 array to
  // get count of positions.
  int prefixSum[N];
  prefixSum[0] = 0;
  for (int i = 1; i < N; i++) {
    prefixSum[i] = prefixSum[i - 1] + arr[i];
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    // gives the count of 1 positions in O(1).
    int ans = prefixSum[r] - prefixSum[l - 1];
    cout << ans << "\n";
  }
}
