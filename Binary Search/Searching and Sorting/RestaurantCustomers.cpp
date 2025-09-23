// Problem: Restaurant Customers
// approach - sweep line algorithm - counting number of overlapping intervals at any point of time

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> events;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, +1}); // arrival
        events.push_back({b, -1}); // leaving
    }

    sort(events.begin(), events.end());

    int curr = 0, maxCustomers = 0;
    for (auto [time, type] : events) {
        curr += type;
        maxCustomers = max(maxCustomers, curr);
    }

    cout << maxCustomers << "\n";
    return 0;
}
