// Question - Minimum Score Triangulation of Polygon
// URL: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
// You have a convex n-sided polygon where each vertex has a positive integer value.
// You are given an integer array values of length n where values[i] is the value of the ith vertex (0-indexed).
// You want to triangulate the polygon into n - 2 triangles.
// The score of a triangulation is the sum of the scores of all n - 2 triangles in the triangulation.
// The score of a triangle whose vertices have values a, b, and c is a * b * c.
// Return the minimum score of a triangulation of the polygon.

// From 4 - LR DP


class Solution {
public:
    vector<vector<int>> dp;
    vector<int> vals;
    int n;

    int rec(int l, int r){
        // pruning
        if(r - l < 2) return 0; // no triangle possible
        //base case
        if(r - l == 2) return vals[l]*vals[r]*vals[l+1]; // only one triangle possible
        // cache check
        if(dp[l][r] != -1) return dp[l][r];
        // transition
        int ans = INT_MAX;
        for(int k = l+1; k < r; k++){
            int cost = rec(l, k) + rec(k, r) + vals[l]*vals[r]*vals[k];
            ans = min(ans, cost);
        }
        // save and return
        return dp[l][r] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        vals = values;
        n = values.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return rec(0, n-1);
    }
};
