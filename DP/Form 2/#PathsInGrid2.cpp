// 2307. Paths in Matrix Whose Sum Is Divisible by K
// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
// Question - Given a 2D integer array grid and an integer k, return the number of paths in the grid such that the sum of the elements on the path is divisible by k.
// A path in the grid is a sequence of cells starting from the top-left cell (0, 0) and ending at the bottom-right cell (n - 1, m - 1) such that you can only move down or right at any point in time.
// Since the answer may be very large, return it modulo 10^9 + 7.   
// Note that -5 mod 2 = 1 in this problem.

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, K;
        cin >> n >> m >> K;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        // dp[j][c] for current row
        vector<vector<int>> prev(m+1, vector<int>(K+1, 0));
        vector<vector<int>> curr(m+1, vector<int>(K+1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                fill(curr[j].begin(), curr[j].end(), 0); // clear each cell
            }
        }

        // initialize starting cell
        if (grid[0][0] == 0) curr[0][0] = 1;
        else if (K > 0) curr[0][1] = 1;

        for (int i = 0; i < n; i++) {
            swap(prev, curr);
            for (int j = 0; j < m; j++)
                fill(curr[j].begin(), curr[j].end(), 0);

            for (int j = 0; j < m; j++) {
                for (int c = 0; c <= K; c++) {
                    int ways = 0;
                    if (i == 0 && j == 0) {
                        if (grid[0][0] == 0 && c == 0) curr[j][c] = 1;
                        else if (grid[0][0] == 1 && c == 1) curr[j][c] = 1;
                        continue;
                    }

                    // from top
                    if (i > 0) {
                        if (grid[i][j] == 0) ways = (ways + prev[j][c]) % MOD;
                        else if (c > 0) ways = (ways + prev[j][c-1]) % MOD;
                    }
                    // from left
                    if (j > 0) {
                        if (grid[i][j] == 0) ways = (ways + curr[j-1][c]) % MOD;
                        else if (c > 0) ways = (ways + curr[j-1][c-1]) % MOD;
                    }
                    curr[j][c] = ways;
                }
            }
        }

        long long ans = 0;
        for (int c = 0; c <= K; c++) {
            ans = (ans + curr[m-1][c]) % MOD;
        }
        cout << ans << "\n";
    }

    return 0;
}
