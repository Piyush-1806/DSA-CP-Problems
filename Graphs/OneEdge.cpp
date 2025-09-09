// This code calculates the number of pairs of nodes that are not directly connected in an undirected graph.
// It uses DFS to find the size of each connected component and then computes the result based on the sizes of these components.
// The final result is printed as the number of pairs of nodes that are not directly connected.
// The time complexity is O(n + m) where n is the number of nodes and m is the number of edges.
// The space complexity is O(n) for storing the graph and visited nodes.
// This code can be used as a template for similar problems involving connected components in graphs.   

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

const int N = 100010;

vector<int> graph[N];
bool visited[N];
long long temp = 0;

void dfs(int cur)
{
    if (visited[cur])
        return;
    temp++;
    visited[cur] = true;
    for (int u : graph[cur])
    {
        dfs(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));

    long long sqsum = 0, sum = 0;

    for (int i = 1; i <= n; i++)
    {
        temp = 0;
        dfs(i);
        sqsum += temp * temp;
        sum += temp;
    }

    cout << (sum * sum - sqsum) / 2 << "\n";

    return 0;
}
