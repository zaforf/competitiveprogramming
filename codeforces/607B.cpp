#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	vector<vector<int>> dp(n, vector<int>(n, 500));
	for (int k = 0; k < n; k++) {
		for (int i = 0; i + k < n; i++) {
			if (k == 0)  {
				dp[i][i+k] = 1;
			} else if (k == 1) {
				dp[i][i+k] = 1 + (a[i] != a[i+k]);
			} else {
				if (a[i] == a[i+k]) dp[i][i+k] = dp[i+1][i+k-1];
				for (int j = i; j < i + k; j++)
					dp[i][i+k] = min(dp[i][i+k], dp[i][j]+dp[j+1][i+k]);
			}
		}
	}
	cout << dp[0][n-1];
	return 0;
}