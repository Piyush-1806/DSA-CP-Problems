// Problem: 1254. Number of Closed Islands
// Link: https://leetcode.com/problems/number-of-closed-islands/
// Question - Given a 2D grid consists of 0s (land) and 1s (water). An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
// Return the number of closed islands.
//Approach - We can solve this problem using Depth-First Search (DFS). We will iterate through each cell in the grid. If we find a land cell (0) that has not been visited, we will perform a DFS to explore the entire island. During the DFS, we will check if the island touches the boundary of the grid. If it does, we will mark it as not closed. If the DFS completes and the island does not touch the boundary, we will increment our closed island count.    
// We will maintain a visited matrix to keep track of the cells that have already been explored.

class Solution {
public:
    int n, m;
    vector<vector<int>> grid;
    vector<vector<int>> vis;
    
    bool dfs(int i, int j) {
        // if out of bounds -> touches boundary
        if (i < 0 || j < 0 || i >= n || j >= m) return false;
        
        // if water or already visited
        if (grid[i][j] == 1 || vis[i][j]) return true;
        
        vis[i][j] = 1;
        
        bool isClosed = true;
        isClosed &= dfs(i+1, j);
        isClosed &= dfs(i-1, j);
        isClosed &= dfs(i, j+1);
        isClosed &= dfs(i, j-1);
        
        return isClosed;
    }
    
    int closedIsland(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<int>(m, 0));
        
        int count = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    if (dfs(i, j)) count++;
                }
            }
        }
        return count;
    }
};
