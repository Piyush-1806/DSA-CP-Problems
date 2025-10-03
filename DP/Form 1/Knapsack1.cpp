// Atcoder - Knapsack1
// Question link - https://atcoder.jp/contests/dp/tasks/dp_d


#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    
    vector<int> weight(N), value(N);
    for (int i = 0; i < N; ++i) {
        cin >> weight[i] >> value[i];
    }

    vector<long long> dp(W + 1, 0);

    for (int i = 0; i < N; ++i) {
        for (int w = W; w >= weight[i]; --w) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    long long max_value = 0;
    for (int w = 0; w <= W; ++w) {
        max_value = max(max_value, dp[w]);
    }

    cout << max_value << endl;
    return 0;
}
