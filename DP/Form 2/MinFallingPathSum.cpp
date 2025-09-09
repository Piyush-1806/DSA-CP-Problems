// 931. Minimum Falling Path Sum
// https://leetcode.com/problems/minimum-falling-path-sum/  
//Question - Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev = matrix[0];
        
        for (int i = 1; i < n; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                int best = prev[j];
                if (j > 0) best = min(best, prev[j-1]);
                if (j < n-1) best = min(best, prev[j+1]);
                curr[j] = matrix[i][j] + best;
            }
            prev = curr;
        }
        
        return *min_element(prev.begin(), prev.end());
    }
};

