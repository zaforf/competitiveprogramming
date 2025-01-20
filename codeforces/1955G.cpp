#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,m; cin>>n>>m;
	vector<vector<int>> grid(n,vector<int>(m));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin>>grid[i][j];
	int g = gcd(grid[0][0],grid[n-1][m-1]);
	int ans = 1;
	vector<vector<bool>> dp(n,vector<bool>(m));
	for (int x=1;x*x<=g;x++) {
		if (g % x) continue;
		vector<int> fr = {x, g/x};
		for (int t : fr) {
			for (int i=0;i<n;i++)
				dp[i].assign(m,0);
			dp[0][0] = 1;
			for (int i=0;i<n;i++) {
				for (int j=0;j<m;j++) {
					if (i==j && i==0) continue;
					dp[i][j] = (grid[i][j] % t == 0);
					if (!dp[i][j]) continue;
					if (i==0) {
						dp[i][j] = dp[i][j] && dp[i][j-1];
					} else if (j==0) {
						dp[i][j] = dp[i][j] && dp[i-1][j];
					} else {
						dp[i][j] = dp[i][j] && (dp[i-1][j] | dp[i][j-1]);
					}
				}
			}
			if (dp[n-1][m-1]) ans = max(ans, t);
		}
	}
	cout << ans << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}