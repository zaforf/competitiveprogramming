#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
bool vis[MAXN];
int dp[MAXN];
int ans[MAXN];
vector<vector<int>> adj;

int dfs(int node) {
	vis[node] = true;
	for (int nb : adj[node])
		if (!vis[nb])
			dp[node] = max(dp[node],dfs(nb)+1);
	vis[node] = false;
	return dp[node];
}

void maxdist(int node, int pardist) {
	int n = adj[node].size();
	vector<int> pre(n,-1);
	vector<int> suf(n,-1);
	for (int i=1;i<n;i++) 
		if (vis[adj[node][i-1]]) pre[i] = pre[i-1];
		else pre[i] = max(pre[i-1],dp[adj[node][i-1]]);
	for (int i=n-2;i>=0;i--)
		if (vis[adj[node][i+1]]) suf[i] = suf[i+1];
		else suf[i] = max(suf[i+1],dp[adj[node][i+1]]);

	vis[node] = true;
	if (node!=1) ans[node] = pardist;
	for (int i=0;i<n;i++)
		if (!vis[adj[node][i]]) {
			ans[node] = max(ans[node],dp[adj[node][i]]+1);
			maxdist(adj[node][i],max(pardist+1,max(pre[i],suf[i])+2));
		}
	vis[node] = false;
}

int main() {
	int n; cin>>n;
	adj.resize(n+1);
	for (int i=0;i<n-1;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans[1] = dfs(1);
	maxdist(1,0);
	for (int i=1;i<=n;i++) cout << ans[i] << ' ';
	return 0;
}