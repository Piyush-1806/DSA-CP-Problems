// Problem: K-th Value
// approach - sort the array according to the values, then calculate the prefix sums of the frequencies
// then use a map to store the first occurrence of each prefix sum
// then for each query, use lower_bound to find the first prefix sum >= k
// if no such prefix sum exists, print -1
// else print the corresponding value from the map  

#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

signed main(){
	IOS
	int t;
	cin >> t;
	while(t--){
		int n, m, q;
		cin >> n >> m >>q;
		vector<pair<ll, ll>> v(n);

		for(int i = 0; i < n; i++){
			cin >> v[i].first;
			v[i].second = 0;
		}

		for(int i = 0; i < m; i++){
			int l, r;
			cin >> l >> r;
			l--;r--;
			v[l].second++;
			if(r+1 < n){
				v[r+1].second--;
			}
		}

		for(int i = 1; i < n; i++){
			v[i].second += v[i-1].second;
		}

		sort(v.begin(), v.end());

		for(int i = 1; i < n; i++){
			v[i].second += v[i-1].second;
		}

		map<ll, ll> mp;
		for(int i = 0; i < n; i++){
			if(v[i].second == 0) continue;
            if(i && v[i].second == v[i - 1].second) continue;
            mp[v[i].second] = v[i].first;
		}

		while(q--){
			ll k;
			cin >> k;
			if(k > v.back().second){
				cout << "-1 ";
			}
			else{
				auto it = mp.lower_bound(k);
				cout << it->second << " ";
			}
		}

		cout << "\n";

	}

	return 0;
}
