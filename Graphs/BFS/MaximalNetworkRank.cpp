// Problem: 1615. Maximal Network Rank
// Link: https://leetcode.com/problems/maximal-network-rank/
// Question - Given an integer n and an array roads where roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi, the network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
// The maximal network rank of the entire infrastructure is the maximum network rank of all pairs of different cities.
// Return the maximal network rank of the entire infrastructure.
//Approach - We can solve this problem using a brute-force approach by checking all pairs of cities and calculating their network rank. We will maintain a degree array to count the number of roads connected to each city and an adjacency matrix to check if two cities are directly connected.

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        
        // Build degree array and adjacency matrix
        for (auto &road : roads) {
            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
            connected[u][v] = connected[v][u] = true;
        }
        
        int ans = 0;
        
        // Check all pairs of cities
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];
                if (connected[i][j]) rank--; // road counted twice
                ans = max(ans, rank);
            }
        }
        
        return ans;
    }
};
