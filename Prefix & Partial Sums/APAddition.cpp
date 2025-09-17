
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll B[MAXN];
ll C[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    while (Q--) {
        ll a, d, l, r;
        cin >> a >> d >> l >> r;

        ll base = ((a - d * l) % MOD + MOD) % MOD;

        B[l] = (B[l] + base) % MOD;
        B[r + 1] = (B[r + 1] - base + MOD) % MOD;

        C[l] = (C[l] + d) % MOD;
        C[r + 1] = (C[r + 1] - d + MOD) % MOD;
    }

    ll prefixB = 0, prefixC = 0;
    for (int i = 1; i <= N; ++i) {
        prefixB = (prefixB + B[i]) % MOD;
        prefixC = (prefixC + C[i]) % MOD;

        ll ans = (prefixB + prefixC * i) % MOD;
        cout << ans << " ";
    }

    cout << '\n';
    return 0;
}
