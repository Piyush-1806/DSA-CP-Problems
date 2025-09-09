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
 
#define ll long long int
#define LD long double
 
const int N = 200010;
 
int inf = 1e9;
int mod = 1e9 + 7;

vector<int> graph[N];
int diameter = 0;
 
int findDiameter(int cur, int prev) {
    int maxi1 = 0, maxi2 = 0;
    for(int u : graph[cur]) {
        if(u == prev) continue;
        int len = findDiameter(u, cur);
        if(len >= maxi1) {
            maxi2 = maxi1;
            maxi1 = len;
        }
        else if(len > maxi2) {
            maxi2 = len;
        }
    }
    diameter = max(diameter, maxi1 + maxi2 + 1);
    return maxi1 + 1;
}
 
signed main()
{
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    findDiameter(1, -1);
 
    cout << diameter - 1 << "\n";
 
    return 0;
}
