//Question - Subtraction Game
// Link - https://maang.in/problems/Subtraction-Game-1079?resourceUrl=cs100-cp506-pl3409-rs1079&returnUrl=%5B%22%2Fcourses%2FDynamic-Programming-Pro-100%3Ftab%3Dchapters%22%5D
// There are two players, Vivek and Abhishek, who are playing a game with a number x.
// They take turns subtracting a power of 2 (i.e., 1, 2, 4, 8, 16, ...) from x.
// The player who cannot make a move (i.e., when x becomes 0) loses the game.
// Vivek always goes first.
// Given the initial value of x, determine the winner of the game if both players play optimally.   
// Approach - If there exists a move that leaves the opponent in a losing state, then the current state is a winning state. Otherwise, it is a losing state.

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int rec(int x){
    // pruning -> not required
    // base case
    if(x == 0) return 0; // no move possible -> losing state
    // cache check
    if(dp[x] != -1) return dp[x];
    // transition
    int ans = 0;
    for(int m=0; (1<<m) <= x; m++){
        if(rec(x - (1<<m)) == 0){ 
            ans = 1; // found a winning move
            break;
        }
    }
    // save and return
    return dp[x] = ans;
}

void solve(){
    int x;
    cin >> x;
    if(rec(x)) cout << "Vivek\n";
    else cout << "Abhishek\n";
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    dp.assign(3*100000, -1); // allocate large enough dp
    while(t--) solve();
}
