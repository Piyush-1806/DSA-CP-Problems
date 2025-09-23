#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        tickets.insert(price);
    }

    for (int i = 0; i < m; i++) {
        int budget;
        cin >> budget;

        // Find first element > budget
        auto it = tickets.upper_bound(budget);

        if (it == tickets.begin()) {
            // All tickets are more expensive
            cout << -1 << "\n";
        } else {
            // Largest ticket <= budget
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }

    return 0;
}
