// Problem: LR Sum Query
// Question - You are given an array arr of size n. You have to answer q queries of the form l, r. For each query, you have to print the sum of elements from index l to r (both inclusive) modulo 10^9 + 7.
// Input Format - The first line contains two integers n and q, denoting the size of the array and the number of queries. The second line contains n space-separated integers, denoting the elements of the array. The next q lines contain two integers l and r, denoting the range for which you have to find the sum.
// Output Format - For each query, print the sum of elements from index l to r (both inclusive) modulo 10^9 + 7.
// Approach - We will use prefix sums to answer the queries in O(1) time after an O(n) preprocessing step. We will create a prefix sum array where prefixSum[i] will store the sum of elements from index 1 to i. For each query (l, r), the sum can be calculated as prefixSum[r] - prefixSum[l-1]. We will take care of negative values by adding mod and taking modulo again.

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
const int N = 1000001;
int arr[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  ll prefixSum[n + 1];
  prefixSum[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefixSum[i] = prefixSum[i - 1] + arr[i];
    if (prefixSum[i] < 0) prefixSum[i] += mod;
    if (prefixSum[i] >= mod) prefixSum[i] -= mod;
  }
  while (q--) {
    ll l, r;
    cin >> l >> r;
    ll ans = prefixSum[r] - prefixSum[l - 1];
    if (ans < 0) ans += mod;
    if (ans >= mod) ans -= mod;
    cout << ans << "\n";
  }
}
