// Problem: 1091. Shortest Path in Binary Matrix
// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Question - Given an n x n binary matrix grid, return the length of the shortest clearing path in the matrix. If there is no clear path, return -1.
// A clear path in a binary matrix is a path from the top-left cell (0, 0) to the bottom-right cell (n - 1, n - 1) such that:
// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.
//Approach - We can solve this problem using the Breadth-First Search (BFS) algorithm. We will start from the top-left cell and explore all 8 possible directions. We will maintain a queue to keep track of the cells to be explored and a distance counter to keep track of the length of the path. If we reach the bottom-right cell, we return the distance. If we exhaust all possibilities without reaching the bottom-right cell, we return -1.  

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<vector<int>> directions = {
            {1,0}, {-1,0}, {0,1}, {0,-1}, 
            {1,1}, {1,-1}, {-1,1}, {-1,-1}
        };
        
        queue<array<int,3>> q;
        q.push({0,0,1});
        grid[0][0] = 1;
        
        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();
            
            if (x == n-1 && y == n-1) return d;
            
            for (auto &dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                    q.push({nx, ny, d+1});
                    grid[nx][ny] = 1;
                }
            }
        }
        
        return -1;
    }
};
