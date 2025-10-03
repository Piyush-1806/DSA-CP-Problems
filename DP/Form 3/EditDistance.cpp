// Question - Edit Distance
// URL: https://leetcode.com/problems/edit-distance/
// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    //Base Case
    for (int i = 0; i <= n; i++) dp[i][0] = i; // deleting all chars
    for (int j = 0; j <= m; j++) dp[0][j] = j; // inserting all chars

    //Fill DP Table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // no operation needed
            } else {
                int insertOp = dp[i][j - 1] + 1;
                int deleteOp = dp[i - 1][j] + 1;
                int replaceOp = dp[i - 1][j - 1] + 1;
                dp[i][j] = min({insertOp, deleteOp, replaceOp});
            }
        }
    }
    return dp[n][m];
}

int main() {
    string word1, word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;
    return 0;
}

