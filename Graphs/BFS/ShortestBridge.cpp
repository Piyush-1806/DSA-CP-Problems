// Problem: Shortest Bridge
// Link: https://leetcode.com/problems/shortest-bridge/
//Question - You are given an n x n binary matrix grid where 1 represents land and 0 represents water. An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
// You may change 0's to 1's to connect the two islands to form one island.
// Return the smallest number of 0's you must flip to connect the two islands.
// Solution - We can use DFS to mark all cells of the first island and add them to a queue. Then, we can use BFS to expand from these cells until we reach the second island, counting the number of steps taken.
//(Multiple sources BFS approach)

class Solution {
public:
    using state = pair<int,int>;
    #define F first
    #define S second
    vector<vector<int>>vis;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int n, m;

    bool isValid(state neighbour){
        return (neighbour.F>=0 && neighbour.F<n &&
                neighbour.S>=0 && neighbour.S<m);
    }

    void dfsMark(state node, vector<vector<int>>& grid, queue<state>& q){
        vis[node.F][node.S] = 1;
        q.push(node); // add to BFS queue
        for(int i=0; i<4; i++){
            state neighbour = {node.F + dx[i], node.S + dy[i]};
            if(isValid(neighbour) && !vis[neighbour.F][neighbour.S] 
               && grid[neighbour.F][neighbour.S] == 1){
                dfsMark(neighbour, grid, q);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<int>>(n,vector<int>(m,0));

        queue<state> q;
        bool found = false;

        for(int i=0; i<n && !found; i++){
            for(int j=0; j<m && !found; j++){
                if(grid[i][j] == 1){
                    dfsMark({i,j}, grid, q);
                    found = true;
                }
            }
        }

        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                state node = q.front(); q.pop();
                for(int i=0; i<4; i++){
                    state neighbour = {node.F + dx[i], node.S + dy[i]};
                    if(isValid(neighbour) && !vis[neighbour.F][neighbour.S]){
                        if(grid[neighbour.F][neighbour.S] == 1){
                            return steps; // reached second island
                        }
                        vis[neighbour.F][neighbour.S] = 1;
                        q.push(neighbour);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
