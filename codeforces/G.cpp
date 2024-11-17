#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<vector<int>> a(2,vector<int>(n));
	for (int& i : a[0]) cin >> i;
	for (int& i : a[1]) cin >> i;
	if (n==1) {
		cout << a[0][0] + a[1][0];
		return 0;
	}
	vector<vector<int>> dp(n,vector<int>(3));
	dp[0][0] = a[0][0];
	dp[0][1] = a[1][0];
	dp[0][2] = dp[0][0]+dp[0][1];
	for (int i=1;i<n;i++) {
		dp[i][0] = a[0][i] + max(dp[i-1][0],dp[i-1][2]);
		dp[i][1] = a[1][i] + max(dp[i-1][i==1 ? 2 : 1],dp[i-1][2]);
		dp[i][2] = a[0][i] + a[1][i] + max(dp[i-1][0],max(dp[i-1][i==1 ? 2 : 1],dp[i-1][2]));
	}
	cout << max(dp[n-1][1],dp[n-1][2]);
	return 0;
}