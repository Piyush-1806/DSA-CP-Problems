// Problem: Prefix and Partial Sums --- High School Maths

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000009;

// fast exponentiation
long long modpow(long long base, long long exp, long long mod = MOD) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// modular inverse using Fermat’s little theorem
long long modinv(long long x) {
    return modpow(x, MOD - 2, MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long a, b, n;
        cin >> a >> b >> n;

        if (a == 1) {
            long long ans = (1 + (n % MOD) * (b % MOD)) % MOD;
            cout << ans << "\n";
            continue;
        }

        long long an = modpow(a, n); // a^n % MOD
        long long numerator = (an - 1 + MOD) % MOD;
        long long inv = modinv((a - 1 + MOD) % MOD);

        long long seriesSum = (numerator * inv) % MOD; // (a^n - 1)/(a-1)
        long long ans = (an + (b % MOD) * seriesSum) % MOD;

        cout << ans << "\n";
    }
    return 0;
}


