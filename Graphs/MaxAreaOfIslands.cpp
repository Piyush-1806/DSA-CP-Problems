// Problem: 695. Max Area of Island
// Link: https://leetcode.com/problems/max-area-of-island/
// Question - You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.
//Approach - We can solve this problem using Depth-First Search (DFS). We will iterate through each cell in the grid. If we find a land cell (1) that has not been visited, we will perform a DFS to explore the entire island and count its area. We will maintain a visited matrix to keep track of the cells that have already been explored. During the DFS, we will explore all 4 possible directions (up, down, left, right) and increment the area count for each land cell we visit. After exploring an island, we will update the maximum area if the current island's area is greater than the previously recorded maximum area.

class Solution {
public:
    vector<vector<int>> visited;
    int m,n,maxsize,currsize;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    using state = pair<int,int>;

    //check if cell is valid and not visited
    bool feasible(state curr, vector<vector<int>>& grid){
        int x = curr.first;
        int y = curr.second;
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        if(visited[x][y]) return false;
        if(grid[x][y] == 0) return false;
        return true;
    }

    void dfs(state curr, vector<vector<int>>& grid){
        visited[curr.first][curr.second] = 1;
        currsize++;
        for(int i=0; i<4; i++){
            state nxt = {curr.first + dx[i], curr.second + dy[i]};
            if(feasible(nxt,grid)){
                dfs(nxt,grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n,0));
        maxsize = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    currsize = 0; //reset for new island
                    dfs({i,j},grid);
                    maxsize = max(maxsize,currsize);
                }
            }
        }
        return maxsize;
    }
};
