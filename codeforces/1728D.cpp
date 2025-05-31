#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin>>s;
	int n = s.size();
	vector<vector<int>> dp(n+1, vector<int>(n+1));
	for (int k=2;k<=n;k+=2) {
		for (int i=0;i+k-1<n;i++) {
			// abcd
			int ab = dp[i+2][k-2];
			if (ab == 0) ab = s[i]-s[i+1];
			int ad = dp[i+1][k-2];
			if (ad == 0) ad = s[i]-s[i+k-1];
			int dc = dp[i][k-2];
			if (dc == 0) dc = s[i+k-1]-s[i+k-2];
			int da = dp[i+1][k-2];
			if (da == 0) da = s[i+k-1]-s[i];

			dp[i][k] = min(max(ab,ad),max(dc,da));
		}
	}
	if (dp[0][n] < 0)
		cout << "Alice" << endl;
	else if (dp[0][n] > 0)
		cout << "Bob" << endl;
	else
		cout << "Draw" << endl;

	
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}