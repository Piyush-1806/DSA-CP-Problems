// Binary Search - Sweeping line

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isPossible(vector<int>& boards, int k, int maxTime) {
    int painters = 1;
    int currSum = 0;
    for (int length : boards) {
        if (currSum + length <= maxTime) {
            currSum += length;
        } else {
            painters++;
            currSum = length;
            if (painters > k) return false;
        }
    }
    return true;
}

int minTimeToPaint(vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0LL);
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(boards, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> boards(n);
        for (int i = 0; i < n; ++i) {
            cin >> boards[i];
        }
        cout << minTimeToPaint(boards, k) << "\n";
    }

    return 0;
}