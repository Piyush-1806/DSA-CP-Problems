// Word Ladder
// https://leetcode.com/problems/word-ladder/
// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
// 1. Only one letter can be changed at a time.
// 2. Each transformed word must exist in the word list.
// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

class Solution {
public:
    bool diff(const string& s1, const string& s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) cnt++;
            if (cnt > 1) return false;
        }
        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        bool found = false;
        for (auto &w : wordList) {
            if (w == endWord) {
                found = true;
                break;
            }
        }
        if (!found) return 0;

        vector<vector<int>> g(n + 1);
        int startIdx = n;
        for (int i = 0; i < n; i++) {
            if (diff(beginWord, wordList[i])) {
                g[startIdx].push_back(i);
                g[i].push_back(startIdx);
            }
            for (int j = i + 1; j < n; j++) {
                if (diff(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        vector<int> dist(n + 1, 1e9);
        queue<int> q;
        q.push(startIdx);
        dist[startIdx] = 1;

        int endIdx = -1;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                endIdx = i;
                break;
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : g[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return (dist[endIdx] == (int)1e9) ? 0 : dist[endIdx];
    }
};
