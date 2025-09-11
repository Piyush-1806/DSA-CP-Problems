// Problem Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// Question - Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.
// Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.
// Approach - We can find the nodes with indegree 0. These nodes are the only nodes from which we can reach all other nodes in the graph.

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> indeg(n, 0);

        // Count indegree for each node
        for (auto &e : edges) {
            indeg[e[1]]++;
        }

        // Collect nodes with indegree 0
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
