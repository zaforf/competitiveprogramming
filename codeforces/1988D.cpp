#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 3e5+1;
int a[MAXN];

void dfs(int node, int par, vector<vector<int>>& adj, vector<vector<int>>& dp) {
	for (int nb : adj[node])
		if (nb != par)
			dfs(nb, node, adj, dp);

	for (int i=1;i<20;i++) {
		int c = 0;
		for (int nb : adj[node]) {
			int mn = LLONG_MAX;
			for (int j=1;j<20;j++)
				if (j!=i)
					mn = min(mn,dp[nb][j]);
			c += mn;
		}
		dp[node][i] = c + i*a[node];
	}
}


void solve() {
	int n; cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	vector<vector<int>> adj(n+1), dp(n+1,vector<int>(20));
	for (int i=0;i<n-1;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0, adj, dp);
	int ans = dp[1][1];
	for (int i=1;i<20;i++) ans = min(ans,dp[1][i]);
	cout << ans << '\n';
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}