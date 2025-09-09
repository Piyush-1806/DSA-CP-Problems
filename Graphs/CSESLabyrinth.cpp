// CSESLabyrinth.cpp
// This code implements a solution to find the shortest path in a labyrinth represented by a grid.
// It uses a breadth-first search (BFS) approach to explore the grid and find the path from the start point 'A' to the end point 'B'.
// The grid is represented as a 2D array of characters, where '.' represents an empty cell, '#' represents a wall,
// 'A' is the starting point, and 'B' is the ending point.
// The algorithm uses a queue to explore the grid and keeps track of visited cells to avoid cycles.
// The time complexity is O(n * m) where n is the number of rows and m is the number of columns in the grid.
// The space complexity is O(n * m) for the visited array and the queue.
// This code can be used to find the shortest path in a labyrinth or grid.
// Input format: First line contains n (number of rows) and m (number of columns), followed by n lines each containing m characters representing the grid.
// Output format: If a path exists, it prints "YES" followed by the number of steps and the sequence of steps taken to reach from 'A' to 'B'. If no path exists, it prints "NO".
// Note: The code assumes that the grid is rectangular and that 'A' and 'B' are guaranteed to be present in the grid.


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

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

int n, m;
char A[1000][1000];
bool vis[1000][1000];

// previousStep stores the previous direction that we moved in to arrive at
// this cell
int previous_step[1000][1000];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string step_dir = "URDL";

int main() {
	cin >> n >> m;

	queue<ii> q;
	ii begin, end;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'A') {
				begin = mp(i, j);
			} else if (A[i][j] == 'B') {
				end = mp(i, j);
			}
		}
	}

	q.push(begin);
	vis[begin.f][begin.s] = true;

	while (!q.empty()) {
		ii u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			ii v = mp(u.f + dx[i], u.s + dy[i]);
			if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;
			if (A[v.f][v.s] == '#') continue;
			if (vis[v.f][v.s]) continue;
			vis[v.f][v.s] = true;
			previous_step[v.f][v.s] = i;
			q.push(v);
		}
	}

	if (vis[end.f][end.s]) {
		cout << "YES" << endl;
		vector<int> steps;
		while (end != begin) {
			int p = previous_step[end.f][end.s];
			steps.push_back(p);
			// undo the previous step to get back to the previous square
			// Notice how we subtract dx/dy, whereas we added dx/dy before
			end = mp(end.f - dx[p], end.s - dy[p]);
		}
		reverse(steps.begin(), steps.end());

		cout << steps.size() << endl;
		for (char c : steps) { cout << step_dir[c]; }
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
}
