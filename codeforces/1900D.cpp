#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	unordered_map<int,vector<int>> indices;
	vector<int> a(n);
	for (int& i : a) cin>>i;
	sort(a.begin(),a.end());
	int m = a.back();
	for (int i=0;i<n;i++)
		indices[a[i]].push_back(i);

	vector<vector<int>> div_to_indices(m+1);
	for (int i=1;i<=m;i++)
		for (int j=i;j<=m;j+=i)
			if (indices.contains(j))
				div_to_indices[i].insert(div_to_indices[i].end(), indices[j].begin(), indices[j].end());

	vector<long long> dp(m+1);
	for (int i=1;i<=m;i++) {
		int sz = div_to_indices[i].size();
		for (int j=0;j<sz;j++)
			dp[i] += j * (n - div_to_indices[i][j] - 1ll);
	}

	for (int i=m;i>0;i--)
		for (int j=i+i;j<=m;j+=i)
			dp[i] -= dp[j];

	long long ans = 0;
	for (int i=1;i<=m;i++)
		ans += i * dp[i];
	cout << ans << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}