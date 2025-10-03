// Question - Matrix Chain Multiplication
// URL: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
// Given a sequence of matrices, find the most efficient way to multiply these matrices together.
// The problem is not actually to perform the multiplications, but merely to decide in which order
// to perform the multiplications.
// We have many options to multiply a given chain of matrices because matrix multiplication is associative.
// For example, if we had four matrices A, B, C, and D, we have several options to perform the multiplications, such as
// ((AB)C)D, (A(BC))D, (AB)(CD), A((BC)D), and A(B(CD)).
// However, the order in which we perform the multiplications can have a significant impact on the number of operations required.
// For example, suppose A is a 10x30 matrix, B is a 30x5 matrix, and C is a 5x60 matrix.
// Then,
// - if we compute (AB)C, the number of operations required is 10*30*5 + 10*5*60 = 4500
// - if we compute A(BC), the number of operations required is 30*5*60 + 10*30*60 = 27000
// Thus, the order of multiplication matters a lot. The problem is to find the most efficient way to multiply these matrices together.



#include<bits/stdc++.h>
using namespace std;

int n;
int x[1010], y[1010]; // this both represent dimension of matrix.

int dp[1010][1010]; // memoization table (fast look-up).

int rec(int l, int r) {
	// pruning
	if(l>r) return 0;
	// basecase
	if(l==r) return 0; // if one matrix, then cost will be 0.
	// cache-check
	if(dp[l][r] != -1) {
		return dp[l][r];
	}
	// compute
	int ans = 1e9; // find min. cost
	for(int mid=l; mid<r; mid++) {
	    ans = min(ans, rec(l,mid) + rec(mid+1, r) + x[l]*y[mid]*y[r]);
	}
	// save & return
	return dp[l][r] = ans;
}


int main() {


	cin>>n;


	for(int i=1; i<=n; i++) {
		cin>>x[i]>>y[i];
	}


	memset(dp,-1,sizeof(dp));


	cout << rec(1,n) << endl;

}
