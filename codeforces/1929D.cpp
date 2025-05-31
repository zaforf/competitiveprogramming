#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

void recurse(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& dp) {
	vis[node] = 1;
	int res = 1;
	for (int nb : adj[node]) {
		if (!vis[nb])
			recurse(nb, adj, vis, dp);
		res = (res * (dp[nb] + 1)) % MOD;
	}
	dp[node] = res;
}

void solve() {
	int n; cin>>n;
	vector<vector<int>> adj(n);
	for (int i=0;i<n-1;i++) {
		int a,b;cin>>a>>b;a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> vis(n);
	vector<int> dp(n);
	recurse(0, adj, vis, dp);
	int ans = 1;
	for (int i=0;i<n;i++)
		ans = (ans + dp[i]) % MOD;
	cout << ans << endl;
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}