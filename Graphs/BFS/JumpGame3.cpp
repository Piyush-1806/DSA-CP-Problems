// Problem Link: https://leetcode.com/problems/jump-game-iii/
// Question - Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
// Approach - We can model this problem as a graph where each index is a node and there is an edge between two nodes if we can jump from one index to another. We can then use DFS to check if we can reach any index with value 0.

class Solution {
public:
    vector<int> vis;
    
    bool rec(int idx, vector<int>& arr) {
        int n = arr.size();
        
        // out of bounds
        if (idx < 0 || idx >= n) return false;
        // already visited
        if (vis[idx]) return false;
        // reached target
        if (arr[idx] == 0) return true;

        vis[idx] = 1;
        
        int it1 = idx + arr[idx];
        int it2 = idx - arr[idx];
        
        return rec(it1, arr) || rec(it2, arr);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vis.assign(n, 0);
        return rec(start, arr);
    }
};
