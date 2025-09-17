
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll A[MAXN], powK[MAXN], invK[MAXN], prefix[MAXN];

ll modpow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    ll K;
    cin >> N >> Q >> K;

    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    powK[0] = 1;
    for (int i = 1; i <= N + 1; ++i)
        powK[i] = powK[i - 1] * K % MOD;

    for (int i = 0; i <= N + 1; ++i)
        invK[i] = modpow(powK[i], MOD - 2);

    for (int i = 1; i <= N; ++i) {
        ll Ai = (A[i] % MOD + MOD) % MOD;
        ll Bi = Ai * powK[i] % MOD;
        prefix[i] = (prefix[i - 1] + Bi) % MOD;
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;

        ll rangeSum = (prefix[R] - prefix[L - 1] + MOD) % MOD;
        ll ans = rangeSum * invK[L] % MOD;
        cout << ans << '\n';
    }

    return 0;
}

