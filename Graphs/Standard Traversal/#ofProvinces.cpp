// https://leetcode.com/problems/number-of-provinces/description/
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.    

//Approach: Count the number of connected components in an undirected graph using DFS.  


class Solution {
vector<vector<int>> g;
vector<int> visited;
public:

    void dfs(int node){
        visited[node]=1;
        for(auto v: g[node]){
            if(!visited[v]) dfs(v);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        g.resize(size);
        visited.assign(size,0);
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(i!=j && isConnected[i][j]==1){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int num_comp = 0;
        for(int i=0; i<size; i++){
            if(!visited[i]){
                dfs(i);
                num_comp++;
            }
        }
        return num_comp;
    }
};