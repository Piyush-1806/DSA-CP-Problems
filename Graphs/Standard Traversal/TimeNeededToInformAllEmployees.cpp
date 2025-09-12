//` Problem: 1376. Time Needed to Inform All Employees
// Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Question - A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company has a unique ID headID.
// Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.
// The head of the company wants to inform all the employees of the company of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know the news.
// The i-th employee needs informTime   [i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).
// Return the number of minutes needed to inform all the employees about the urgent news.
//Approach - We can solve this problem using Depth-First Search (DFS). We will build a tree representation of the employees and their subordinates using an adjacency list. Starting from the head of the company, we will perform a DFS to calculate the total time needed to inform all employees.
// For each employee, we will recursively calculate the time needed for their subordinates to be informed and add the informTime of the current employee. The maximum time among all subordinates will be the total time needed for that employee to inform their subordinates.
// Finally, we will return the total time needed for the head of the company to inform all employees.
class Solution {
public:
    int dfs(int u, vector<vector<int>>& adj, vector<int>& informTime) {
        int maxTime = 0;
        for (int v : adj[u]) {
            maxTime = max(maxTime, dfs(v, adj, informTime));
        }
        return informTime[u] + maxTime;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        
        // build tree
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }
        
        return dfs(headID, adj, informTime);
    }
};
