#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	set<int> in;
	vector<pair<int,int>> a(n);
	unordered_map<int, int> ind_map;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		a[i] = {x,i};
		ind_map[i] = x;
	}
	vector<int> dp(n,1);
	sort(a.begin(), a.end(), greater<pair<int,int>>());
	for (int i=0;i<n;i++) {
		int x = a[i].first, idx = a[i].second;
		auto it = in.lower_bound(idx);
		if (it != in.begin()) {
			it--;
			if (ind_map[*it] > x)
				dp[idx] = dp[*it] + 1;
		}
		it = in.upper_bound(idx);
		if (it != in.end()) {
			if (ind_map[*it] > x)
				dp[idx] = max(dp[idx], dp[*it] + 1);
			else
				dp[idx] = max(dp[idx], dp[*it]);
		}
		in.insert(idx);
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;




	return 0;
}