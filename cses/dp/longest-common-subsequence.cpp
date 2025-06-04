#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
		}
	}
	cout << dp[n][m] << endl;
	int i = n, j = m;
	vector<int> lcs;
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			lcs.push_back(a[i - 1]);
			--i; --j;
		} else if (dp[i - 1][j] >= dp[i][j - 1]) {
			--i;
		} else {
			--j;
		}
	}
	reverse(lcs.begin(), lcs.end());
	for (int i : lcs) cout << i << " ";
	return 0;
}