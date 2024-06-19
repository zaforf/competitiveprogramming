#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main() {
	int n,w; cin>>n>>w;
	vector<int> ws(n);
	vector<pair<int,int>> dp(1048576+1,{21,0});
	dp[0].f=1;
	dp[0].s=w;
	for (int& i : ws) cin>>i;
	for (int i=1;i<(1<<n);i++) {
		for (int j=0;j<n;j++) {
			if (i & (1<<j)) {
				if (ws[j]<=dp[i^(1<<j)].s && dp[i^(1<<j)].f<=dp[i].f) {
					dp[i].f=dp[i^(1<<j)].f;
					dp[i].s=max(dp[i].s,dp[i^(1<<j)].s-ws[j]);
				} else if (dp[i^(1<<j)].f+1<=dp[i].f) {
					dp[i].f=dp[i^(1<<j)].f+1;
					dp[i].s=max(dp[i].s,max(dp[i^(1<<j)].s,w-ws[j]));
				}
			}
		}
	}
	cout << dp[(1<<n)-1].f;
	return 0;
}