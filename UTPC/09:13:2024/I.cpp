#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k; cin>>n>>k;
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2,1e9))); // left, right
	// time it takes to get to i or i+l
	vector<int> a(n);
	for (int& i : a) cin>>i;
	dp[k-1][0][0] = dp[k-1][0][1] = 0;
	for (int l=1;l<n;l++)
		for (int i=0;i+l<n;i++) {
			// consider the range a[i] to a[i+l]
			dp[i][l][0] = dp[i+1][l-1][0]+1;
			dp[i][l][0] = min(dp[i][l][0],dp[i+1][l-1][1]+l);
			if (dp[i][l][0] >= a[i]) dp[i][l][0] = 1e9;

			dp[i][l][1] = dp[i][l-1][0]+l;
			dp[i][l][1] = min(dp[i][l][1],dp[i][l-1][1]+1);
			if (dp[i][l][1] >= a[i+l]) dp[i][l][1] = 1e9;
		}
	int res = min(dp[0][n-1][0],dp[0][n-1][1]);
	cout << (res == 1e9 ? -1 : res) << endl;
	return 0;
}