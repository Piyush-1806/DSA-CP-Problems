#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long d;
    cin >> n >> d;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = upper_bound(arr.begin(), arr.end(), arr[i] + d) - arr.begin();
        long long len = pos - i - 1; // number of points strictly after i within d
        if (len >= 2) ans += (len * (len - 1)) / 2;
    }
    cout << ans << "\n";
}
