#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& i : a) cin>>i;
	sort(a.begin(),a.end());
	vector<int> c(n);
	int k = 0;
	for (int i=0;i<n;i++) {
		if (i>0 && a[i]!=a[i-1]) k++;
		c[k]++;
	}
	c.resize(k+1);
	n = k+1;

	vector<vector<int>> dp(n,vector<int>(n,1e9));
	dp[0][0] = 0;
	// minimum cost of eating j types of cakes for indices up to i
	for (int i=1;i<n;i++) {
		for (int j=0;j<n;j++) {
			dp[i][j] = dp[i-1][j];
			if (j && (dp[i-1][j-1]+c[i]) + (j-1) <= i)
				dp[i][j] = min(dp[i][j],dp[i-1][j-1]+c[i]);
		}
	}
	int bobeats = 0;
	for (int j=0;j<n;j++) if (dp[n-1][j]<1e9) bobeats = j;
	cout << n-bobeats << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}