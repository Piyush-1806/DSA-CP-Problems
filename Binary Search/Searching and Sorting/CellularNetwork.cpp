// Binary Search - Sweeping Line

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> cities(n), towers(m);
    for (int i = 0; i < n; i++) cin >> cities[i];
    for (int i = 0; i < m; i++) cin >> towers[i];

    sort(towers.begin(), towers.end()); // make sure towers are sorted
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long cur = cities[i];
        auto it = lower_bound(towers.begin(), towers.end(), cur);

        long long dist = LLONG_MAX;
        if (it != towers.end()) dist = *it - cur; // tower on right
        if (it != towers.begin()) dist = min(dist, cur - *(prev(it))); // tower on left

        ans = max(ans, dist);
    }

    cout << ans << "\n";
    return 0;
}
