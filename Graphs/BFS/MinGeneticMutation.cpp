// Problem: 433. Minimum Genetic Mutation
// Link: https://leetcode.com/problems/minimum-genetic-mutation/
// Question - A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".
// Suppose we need to investigate about a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.
// For example, "AACCGGTT" -> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
// Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.
// Note that the starting point is assumed to be valid, so it might not be included in the bank.
// Solution - We can model this problem as a graph where each gene string is a node and there is an edge between two nodes if they differ by exactly one character. We can then use BFS to find the shortest path from the start gene to the end gene.
//TC -> O(Bank.Size()^2+Bank.Size()*8). -> O(Bank.Size()^2)

class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;
    vector<int> dist;

    bool diff(string& s1, string& s2){
        int num = 0;
        for(int i = 0; i < 8; ++i){
            if (s1[i] != s2[i]) {
                ++num;
                if (num > 1) return false;
            }
        }
        return num == 1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {

        int sze = bank.size();
        bool foundEnd = false;
        for (string &b : bank) {
            if (b == endGene) {
                foundEnd = true;
                break;
            }
        }
        if (!foundEnd) return -1;
        g.clear();
        g.resize(sze + 2);
        const int INF = (int)1e9;
        vis.assign(sze + 2, 0);
        dist.assign(sze + 2, INF);

        int startIdx = -1, endIdx = -1;
        for (int i = 0; i < sze; ++i) {
            if (bank[i] == startGene) startIdx = i;
            if (bank[i] == endGene) endIdx = i;
        }

        for (int i = 0; i < sze; ++i) {
            if (diff(bank[i], startGene)) {
                g[i].push_back(sze);
                g[sze].push_back(i);
            }
            if (diff(bank[i], endGene)) {
                g[i].push_back(sze + 1);
                g[sze + 1].push_back(i);
            }
            for (int j = i + 1; j < sze; ++j) {
                if (diff(bank[i], bank[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        int startNode = (startIdx != -1 ? startIdx : sze);
        int targetNode = (endIdx != -1 ? endIdx : sze + 1);

        queue<int> q;
        q.push(startNode);
        dist[startNode] = 0;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int v : g[cur]) {
                if (dist[v] > dist[cur] + 1) {
                    dist[v] = dist[cur] + 1;
                    q.push(v);
                }
            }
        }

        return (dist[targetNode] == INF) ? -1 : dist[targetNode];
    }
};
