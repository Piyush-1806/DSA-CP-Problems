// Problem: https://leetcode.com/problems/keys-and-rooms/
// The goal is to determine if all rooms can be visited starting from room 0, given
// that each room may contain keys to other rooms.
// Approach
// 1. Use DFS to explore the rooms starting from room 0.
// 2. Maintain a visited array to track which rooms have been visited.  
// 3. After the DFS, check if all rooms have been visited.
// 4. If all rooms are visited, return true; otherwise, return false.
// 5. The graph is represented using an adjacency list where each room points to the rooms it has keys for.

class Solution {
vector<int> visited;
public:
    void dfs(int node, vector<vector<int>>& rooms){
        visited[node] = 1;
        for(auto v: rooms[node]){
            if(!visited[v]){
                dfs(v,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        visited.assign(size,0);
        dfs(0,rooms);
        for(int i=1; i<size; i++){
            if(visited[i]!=1) return false;
        }
        return true;
    }
};