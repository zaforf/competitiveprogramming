#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> state(n+1,0);
	for (int j = 0; j < 2; j++) {
		string s; cin>>s;
		for (int i = 0; i < s.size(); i++)
			if (s[i]=='#') state[i] |= 2-j;
	}
	vector<vector<int>> dp(n+1,vector<int>(4,0));
	dp[n][0] = 1;
	for (int i=n-1;i>=0;i--) {
		for (int j=3;j>=0;j--) {
			if (j == 3) {
				dp[i][j] = dp[i+1][state[i+1]];
			} else if (j == 2) {
				if (i+1==n || state[i+1]&1) continue; // can't place
				dp[i][j] += dp[i+1][state[i+1]|1]; // one right
			} else if (j == 1) {
				if (i+1==n || state[i+1]&2) continue; // can't place
				dp[i][j] += dp[i+1][state[i+1]|2]; // one right
			} else if (j == 0) {
				dp[i][j] += dp[i+1][state[i+1]]; // down
				if (i+1<n && !state[i+1]) dp[i][j] += dp[i+2][state[i+2]]; // two right
			}
			if (dp[i][j]>1) dp[i][j] = 2;
		}
	}
	int res = dp[0][state[0]];
	if (res == 0)
		cout << "None\n";
	else if (res == 1)
		cout << "Unique\n";
	else
		cout << "Multiple\n"; 
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}