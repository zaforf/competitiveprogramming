#include <bits/stdc++.h>
using namespace std;

int score(int diff) {
	diff = abs(diff);
	if (diff < 16) return 7;
	if (diff < 24) return 6;
	if (diff < 44) return 4;
	if (diff < 103) return 2;
	return 0;
}

int main() {
	int n,m; cin>>n>>m;
	vector<int> e(n);
	vector<int> a(m);
	for (int& i : e) cin>>i;
	for (int& i : a) cin>>i;
	vector<vector<int>> dp(m,vector<int>(n+1,0));
	// considering first i, matching with first j
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			if (i>0) dp[i][j+1] = dp[i-1][j+1]; // dont match this one
			if (j>0) dp[i][j+1] = max(dp[i][j+1],dp[i][j]); // match this one with anything before
			// match this one with j
			if (i>0)
				dp[i][j+1] = max(dp[i][j+1],dp[i-1][j]+score(a[i]-e[j]));
			else
				dp[i][j+1] = max(dp[i][j+1],score(a[i]-e[j]));
		}
	}
	cout << *max_element(dp.back().begin(),dp.back().end());
	return 0;
}