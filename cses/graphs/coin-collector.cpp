#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
const int MAXN = 1e5+1;
int val[MAXN], comp[MAXN], comp_val[MAXN],ans[MAXN],k=0;
bool vis[MAXN];
vector<vector<int>> adj,adj_t,compgraph;
vector<int> ord;

void dfs(int x) {
	vis[x]=true;
	for (int nb : adj[x])
		if (!vis[nb])
			dfs(nb);
	ord.push_back(x);
}

void assign(int x) {
	comp[x] = k;
	comp_val[k] += val[x];
	for (int nb : adj_t[x])
		if (!comp[nb])
			assign(nb);
}

int dp(int i) {
	if (ans[i]) return ans[i];
	ans[i] = comp_val[i];
	for (int nb : compgraph[i])
		ans[i] = max(ans[i], comp_val[i]+dp(nb));
	return ans[i];
}

int32_t main() {
	cin>>n>>m;
	adj.resize(n+1);adj_t.resize(n+1);
	for (int i=1;i<=n;i++) cin>>val[i];
	for (int i=0;i<m;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj_t[b].push_back(a);
	}
	for (int i=1;i<n;i++)
		if (!vis[i])
			dfs(i);
	reverse(ord.begin(),ord.end());
	for (int i : ord)
		if (!comp[i]) {
			k++;
			assign(i);
		}
	compgraph.resize(k+1);
	for (int i=1;i<=n;i++) {
		for (int nb : adj[i]) {
			if (comp[nb]==comp[i]) continue;
			compgraph[comp[i]].push_back(comp[nb]);
		}
	}
	int ans = 0;
	for (int i=1;i<=k;i++)
		ans = max(ans,dp(i));
	cout << ans << endl;
	return 0;
}