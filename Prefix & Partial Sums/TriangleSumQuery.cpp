//Approach - We need to find the sum of all the values in the triangular region. We already know how to do that if the shape was of rectangles. So lets try to break this problem too into smaller rectangles and triangles.
//Let us define two prefix sum arrays - rect[i][j] = sum of all values in the rectangle from (1,1) to (i,j) and tri[i][j] = sum of all values in the triangle from (1,1) to (i,j).
//Now, we can easily calculate rect[i][j] using the formula - rect[i][j] = rect[i-1][j] + rect[i][j-1] - rect[i-1][j-1] + arr[i][j]
//Now, to calculate tri[i][j], we can break the triangle into a smaller triangle and a rectangle. The smaller triangle will be tri[i-1][j-1] and the rectangle will be rect[i][j] - rect[i][j-1]. So, the formula for tri[i][j] will be - tri[i][j] = tri[i-1][j-1] + rect[i][j] - rect[i][j-1]
//Now, to find the sum of the values in the triangular region with bottom right corner (x,y) and side length l, we can use the formula - ans = tri[x][y] - tri[x-l][y-l] - (rect[x-l][y] - rect[x-l][y-l])
//We need to take care of the cases when x-l or y-l is less than 0.
//Finally, we need to take care of the modulo operation.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int mod = 1000000007;
typedef vector<ll> vll;

ll n, m;

void print(vector<vll> vec) {
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      cout << vec[i][j] << " ";
    }
    cout << endl;
  }
}

void solve() {
  ll i, j, k, q;
  cin >> n >> m >> q;

  vector<vll> arr(n + 1, vll(m + 1, 0));
  vector<vll> rect(n + 1, vll(m + 1, 0));
  vector<vll> tri(n + 1, vll(m + 1, 0));

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> arr[i][j];
      rect[i][j] =
          (rect[i - 1][j] + rect[i][j - 1] - rect[i - 1][j - 1] + arr[i][j]) %
          mod;
      tri[i][j] = (tri[i - 1][j - 1] + rect[i][j] - rect[i][j - 1]) % mod;
    }
  }

  while (q--) {
    ll x, y, l;
    cin >> x >> y >> l;

    i = max(0ll, x - l);
    j = max(0ll, y - l);

    ll ans = tri[x][y] - tri[i][j] - (rect[i][y] - rect[i][j]);
    ans = (ans % mod + mod) % mod;

    cout << ans << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // #ifndef ONLINE_JUDGE
  // freopen(“input.txt”, “r”, stdin);
  // freopen(“output.txt”, “w”, stdout);
  // #endif

  int t = 1;
  // cin>>t;

  while (t--) solve();

  return 0;
}


