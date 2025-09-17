// MaxValInRectangle.cpp
// Given a series of rectangle updates on a 2D grid, this program computes the maximum
// value in the grid after all updates and counts how many cells contain that maximum value.
// It uses a 2D difference array to efficiently apply the updates and then computes the final values
// using a 2D prefix sum approach. 
// The program reads the dimensions of the grid and the number of updates, processes each update,
// and finally outputs the maximum value and its frequency in the grid.
// Time Complexity: O(N * M + Q) where N and M are the dimensions of the grid and Q is the number of updates.
// approach - 2D difference array + 2D prefix sum

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
typedef long long ll;

ll diff[MAXN][MAXN];  // Difference array
ll mat[MAXN][MAXN];   // Final matrix after all queries

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    while (Q--) {
        int x1, y1, x2, y2;
        ll C;
        cin >> x1 >> y1 >> x2 >> y2 >> C;

        diff[x1][y1] += C;
        diff[x1][y2 + 1] -= C;
        diff[x2 + 1][y1] -= C;
        diff[x2 + 1][y2 + 1] += C;
    }

    //Convert diff to final matrix using 2D prefix sum
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            mat[i][j] = diff[i][j]
                      + mat[i - 1][j]
                      + mat[i][j - 1]
                      - mat[i - 1][j - 1];

    //Find max value and count of cells with max value
    ll max_val = LLONG_MIN;
    int count = 0;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            if (mat[i][j] > max_val) {
                max_val = mat[i][j];
                count = 1;
            } else if (mat[i][j] == max_val) {
                count++;
            }
        }

    cout << max_val << " " << count << '\n';
    return 0;
}