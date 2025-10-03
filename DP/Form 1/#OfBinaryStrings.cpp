// Problem: Count the number of binary strings of length n that do not contain "0100" as a substring.
// Link: https://maang.in/problems/Count-of-Binary-Strings-503?resourceUrl=cs100-cp507-pl3410-rs503&returnUrl=%5B%22%2Fcourses%2FDynamic-Programming-Pro-100%3Ftab%3Dchapters%22%5D

// Approach: Use an automaton (finite state machine) to track the states of matching the pattern "0100" and count valid strings using dynamic programming.
// Time Complexity: O(n)


#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
const int MAXN = 1e6 + 5;
string pattern = "0100";
int m = 4; // pattern length

// Precomputed answers
long long ans[MAXN];

// Transition function: trans[state][char] = next_state
int trans[5][2];

// Build the automaton transition table (KMP-style)
void buildAutomaton() {
    // For each state (0 to 4) and each character ('0' or '1')
    for (int state = 0; state <= m; state++) {
        for (int c = 0; c <= 1; c++) {
            char ch = '0' + c;
            
            if (state == m) {
                // Already matched the pattern, stay in accepting state
                trans[state][c] = m;
            } else if (pattern[state] == ch) {
                // Character matches, advance to next state
                trans[state][c] = state + 1;
            } else {
                // Character doesn't match, find longest proper prefix
                // that is also a suffix of pattern[0..state-1] + ch
                int next_state = 0;
                string cur = pattern.substr(0, state) + ch;
                
                // Check all possible prefix lengths
                for (int len = state; len >= 1; len--) {
                    if (cur.substr(cur.length() - len) == pattern.substr(0, len)) {
                        next_state = len;
                        break;
                    }
                }
                trans[state][c] = next_state;
            }
        }
    }
}

// Fast power for computing 2^n mod
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void precompute() {
    buildAutomaton();
    
    // dp[i][j] = number of strings of length i in state j
    // Use rolling array to save space
    vector<long long> dp(5, 0);
    vector<long long> ndp(5, 0);
    
    dp[0] = 1; // Empty string is in state 0
    
    for (int i = 0; i < MAXN - 1; i++) {
        fill(ndp.begin(), ndp.end(), 0);
        
        for (int state = 0; state < 5; state++) {
            if (dp[state] == 0) continue;
            
            // Add '0'
            int next_state = trans[state][0];
            ndp[next_state] = (ndp[next_state] + dp[state]) % mod;
            
            // Add '1'
            next_state = trans[state][1];
            ndp[next_state] = (ndp[next_state] + dp[state]) % mod;
        }
        
        swap(dp, ndp);
        
        // Answer for length i+1: total strings - strings that reached state 4
        long long total = power(2, i + 1, mod);
        ans[i + 1] = (total - dp[4] + mod) % mod;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << ans[n] << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}