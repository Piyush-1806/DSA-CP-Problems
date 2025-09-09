// Problem: https://leetcode.com/problems/find-eventual-safe-states/
// The goal is to find all nodes in a directed graph that eventually lead to terminal nodes (nodes with no outgoing edges).
// Approach
// 1. Use DFS to explore each node.
// 2. Maintain a state array to track the visitation status of each node (unvisited, visiting, safe).
// 3. If we encounter a node that is currently being visited, it indicates a cycle, and we mark it as unsafe.
// 4. If we reach a terminal node or all neighbors are safe, we mark the current node as safe.
// 5. Collect all safe nodes and return them in sorted order.   

class Solution {
    vector<int> state; // 0 = unvisited, 1 = visiting, 2 = safe
    
    bool dfs(int node, vector<vector<int>>& graph) {
        if (state[node] != 0) return state[node] == 2; // return true if safe

        state[node] = 1; // mark visiting
        for (int nei : graph[node]) {
            if (!dfs(nei, graph)) return false; // if neighbor not safe -> cycle
        }
        state[node] = 2; // mark safe
        return true;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        state.assign(n, 0);
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph)) ans.push_back(i);
        }
        return ans;
    }
};
