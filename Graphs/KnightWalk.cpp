/*
KnightWalk.cpp

Approach
Treat the 𝑁×𝑁 chessboard as a graph where each cell is a node.Edges exist between nodes that a knight can jump between.

Use Breadth-First Search (BFS) starting from (Sx, Sy) to find the shortest distance to (Fx, Fy).

BFS Logic

Initialize a dist[N+1][N+1] array with -1 (unvisited).
Set dist[Sx][Sy] = 0 and push (Sx, Sy) into a queue.
While queue is not empty:
Pop current position.
For each of the 8 moves:
If the new position is inside the board and not visited, mark distance and push to queue.
Return dist[Fx][Fy] (or -1 if unreachable).
*/

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


int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
	// Complete the function
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, -1));
    queue<pair<int, int>> q;

    dist[Sx][Sy] = 0;
    q.push(make_pair(Sx, Sy));

    while (!q.empty()) {
        pair<int,int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        if (x == Fx && y == Fy) return dist[x][y];

        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return -1;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
