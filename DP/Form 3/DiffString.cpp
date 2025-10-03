
// Question - Diff Utility
// URL: https://cses.fi/problemset/task/1639
#include<bits/stdc++.h>
using namespace std;

int n, m;
string s, t;


int dp[3030][3030];
int back[3030][3030];
int rec(int i, int j) {
	// pruning
	// base-case
	if(i==n && j==m) return 0;


	// cache check
	if(dp[i][j] != -1) return dp[i][j];


	// compute
	int ans = 1e9;
	if(i<n && j<n && s[i] == t[j]) {
		int dis = 1 + rec(i+1, j+1);
		if(dis<ans) {
			ans = dis;
			back[i][j] = 0; // for  0 -> LCS
		}
	}


	if(i<n) {
		int dis = 1 + rec(i+1, j);
		if(dis<ans) {
			ans = dis;
			back[i][j] = 1; // for 1 First string
		}
	}


	if(j<n) {
		int dis = 1 + rec(i, j+1);
		if(dis<ans) {
			ans = dis;
			back[i][j] = 2; // for 2 Second string
		}
	}




	// save & return
	return dp[i][j] = ans;


}


//  Generate string ::


void printer(int i, int j) {
	// base-case
	if(i==n && j==m) return;


	int ch = back[i][j];
	if(ch==0) {
		cout<<s[i]<<" ";
		printer(i+1, j+1);
	} else if(ch==1) {
		cout<<"-"<<s[i]<<" ";
		printer(i+1, j);
	} else {
		cout<<"+"<<t[j]<<" ";
		printer(i, j+1);
	}


}


int main() {


	cin >> s >> t;


	n = s.size();
	m = t.size();


	memset(dp, -1, sizeof(dp));


	cout << rec(0, 0) << endl;


	printer(0,0);


}

