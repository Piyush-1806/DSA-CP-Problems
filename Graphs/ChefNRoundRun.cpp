// ChefNRoundRun.cpp
// This problem involves finding the minimum number of walls to break in a grid to connect two points A and B.
// We can use a modified BFS approach to achieve this.
// The BFS will treat walls as edges with a cost of 1, and free cells as edges with a cost of 0.
// We will use a deque to implement a 0-1   BFS, where we push walls to the back and free cells to the front.
// The goal is to find the minimum cost path from A to B.
// Approach
// 1. Read the grid dimensions and the grid itself. 
// 2. Initialize a distance matrix with INF.
// 3. Perform a BFS starting from point A, updating distances based on whether the next cell is a wall or not.
// 4. If we reach point B, print the distance;
// 5. If point B is unreachable, print -1.
// 6. Use a deque to efficiently manage the BFS queue.
// 7. Use a state structure to represent the current position in the grid.
// 8. Use a vector to store the grid and another vector for the distance matrix.
// 9. Use a pair to represent the coordinates of the points in the grid.
// 10. Use a constant for infinity to represent unreachable cells.
// 11. Use a vector of pairs to represent the directions for movement in the grid.
// 12. Use a function to check if a cell is inside the grid bounds.
// 13. Use a function to perform the BFS and update distances.
// 14. Use a function to solve the problem by reading input and calling the BFS function.
// Time complexity : O(n)


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring> 
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        vector<int> to(N);       // next node from i
        vector<int> indeg(N, 0); // in-degrees

        for (int i = 0; i < N; i++) {
            int nxt = (i + A[i] + 1) % N;
            to[i] = nxt;
            indeg[nxt]++;
        }

        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        // Kahn’s algorithm style pruning
        vector<bool> removed(N, false);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            removed[u] = true;
            int v = to[u];
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }

        // Count nodes that remain (part of cycles)
        int magic = 0;
        for (int i = 0; i < N; i++) {
            if (!removed[i]) magic++;
        }

        cout << magic << "\n";
    }
    return 0;
}
