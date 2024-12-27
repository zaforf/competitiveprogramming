#include <bits/stdc++.h>
using namespace std;

void solve() {
	string a,b,c; cin>>a>>b>>c;
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1));
	for (int i=0;i<n+1;i++) {
		for (int j=0;j<m+1;j++) {
			if (i==0 && j==0) continue;
			else if (i==0) dp[i][j] = dp[i][j-1] + (c[i+j-1]!=b[j-1]);
			else if (j==0) dp[i][j] = dp[i-1][j] + (c[i+j-1]!=a[i-1]);
			else {
				dp[i][j] = dp[i][j-1] + (c[i+j-1]!=b[j-1]);
				dp[i][j] = min(dp[i][j],dp[i-1][j] + (c[i+j-1]!=a[i-1]));
			}
		}
	}
	cout << dp[n][m] << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}