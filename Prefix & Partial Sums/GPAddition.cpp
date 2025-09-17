

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll powK[MAXN];
ll start[MAXN];
ll endval[MAXN];

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

    powK[0] = 1;
    for (int i = 1; i <= N + 5; ++i)
        powK[i] = powK[i - 1] * K % MOD;

    while (Q--) {
        ll A;
        int L, R;
        cin >> A >> L >> R;

        start[L] = (start[L] + A) % MOD;

        ll end_term = A * powK[R - L + 1] % MOD;
        endval[R + 1] = (endval[R + 1] + end_term) % MOD;
    }

    vector<ll> result(N + 1);
    ll gp_sum = 0;

    for (int i = 1; i <= N; ++i) {
        gp_sum = (gp_sum * K % MOD + start[i]) % MOD;
        gp_sum = (gp_sum - endval[i] + MOD) % MOD;
        result[i] = gp_sum;
    }

    for (int i = 1; i <= N; ++i)
        cout << result[i] << " ";
    cout << '\n';

    return 0;
}
