// Rectangle Sum Query
// Given a 2D array, answer multiple queries asking for the sum of elements in a
// specified rectangular subarray, with results taken modulo 1e9 + 7.   
//Approach - Prefix Sums

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1005;

int N, M, Q;
int A[MAXN][MAXN];
long long pref[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> A[i][j];

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            long long val = A[i][j];
            val = (val % MOD + MOD) % MOD;

            pref[i][j] = (val + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]) % MOD;

            if (pref[i][j] < 0) pref[i][j] += MOD;
        }
    }

    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long res = pref[x2][y2];
        res = (res - pref[x1 - 1][y2] + MOD) % MOD;
        res = (res - pref[x2][y1 - 1] + MOD) % MOD;
        res = (res + pref[x1 - 1][y1 - 1]) % MOD;

        cout << res << '\n';
    }

    return 0;
}
