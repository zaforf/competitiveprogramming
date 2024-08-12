#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second

const int MAXN = 1e5+1;
int sz[MAXN], dp[MAXN], ord[MAXN];
bool mark[MAXN];
int k = 1;

void dfs(int node, vector<vector<pii>>& adj) {
	ord[node] = k++;
	for (pii& nb : adj[node]) {
		if (ord[nb.f]) continue;
		mark[nb.s] = true;
		dfs(nb.f,adj);
		sz[node] += sz[nb.f];
	}
	for (pii& nb : adj[node]) {
		if (!mark[nb.s]) {
			if (ord[nb.f]<ord[node]) dp[node]++;
			else dp[node]--;
		} else if (ord[node]<ord[nb.f]) dp[node] += dp[nb.f];
	}
	sz[node]++;
}

void solve() {
	int n,m; cin>>n>>m;
	for (int i=0;i<n+1;i++) sz[i] = dp[i] = ord[i] = 0;
	for (int i=0;i<m+1;i++) mark[i] = 0;
	vector<vector<pii>> adj(n+1);
	for (int i=0;i<m;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back({b,i});
		adj[b].push_back({a,i});
	}
	dfs(1,adj);
	ll ans = 1ll*n*(n-1)/2;
	for (int i=1;i<=n;i++) 
		if (dp[i]==0)
			ans = min(ans,1ll*sz[i]*(sz[i]-1)/2 + 1ll*(n-sz[i])*(n-sz[i]-1)/2);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}