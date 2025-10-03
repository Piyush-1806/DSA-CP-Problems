// Question - Longest Increasing Subsequence (LIS) in nlogn
// Approach - Binary Search + DP
// Link - https://cses.fi/problemset/task/1145
// Explanation - We maintain a list 'lis' where lis[i] is the smallest ending element of an increasing subsequence of length i+1 found so far.
// For each element x in the array, we use binary search to find the position in 'lis' where x can replace an element
// (the first element greater than or equal to x). If x is larger than all elements in 'lis', it extends the largest subsequence found so far.
// The length of 'lis' at the end of the process gives the length of the longest increasing subsequence.
// To reconstruct the actual subsequence, we maintain two auxiliary arrays: 'parent' to track the previous index of each element in the subsequence,
// and 'back' to store the index of the last element of the subsequence of each length.
// Time Complexity - O(n log n)
// Space Complexity - O(n)
// Note - This implementation also reconstructs and prints one of the longest increasing subsequences.

#include <bits/stdc++.h>
using namespace std;


int n;
int x[1010];


int main() {


	cin>>n;


	for(int i=0; i<n; i++) cin>>x[i];


	vector<int> lis;
	int parent[n]; // prev ele.
	int back[n]; // new ele. ending at k idx


	back[0]=-1;
	for(int i=0; i<n; i++) {


		auto it = lower_bound(lis.begin(), lis.end(), x[i]);


		if(it == lis.end()) {
			int len = lis.size();
			parent[i]=back[len];
			lis.push_back(x[i]);
			back[len+1]=i;
		} else {
			int pos = it-lis.begin();
			parent[i]=(pos==0?-1:back[pos]);
			*it = x[i];
			back[pos+1]=i;
		}
	}
	cout << lis.size() << endl;
	
	vector<int> ans;
	int index = back[lis.size()]; // start from last element of LIS
	while(index != -1) {
	     ans.push_back(x[index]);
// 		cout << x[index] << " ";
		index = parent[index];
	}
	
	reverse(ans.begin(), ans.end());
	
	for(auto v : ans) cout << v << " ";


}
