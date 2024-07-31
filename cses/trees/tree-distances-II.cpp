#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5+1;
bool vis[MAXN];
int cnt[MAXN];
ll dist[MAXN], ans[MAXN];
vector<vector<int>> adj;

void dfs(int node) {
	vis[node] = true;
	cnt[node]++;
	for (int nb : adj[node])
		if (!vis[nb]) {
			dfs(nb);
			cnt[node] += cnt[nb];
			dist[node] += dist[nb]+cnt[nb];
		}
	vis[node] = false;
}

void sumdist(int node, ll pardist, ll parcnt) {
	// pardist: distances from parent to node
	ll totsum = 0, totcnt = 0;
	for (int nb : adj[node])
		if (!vis[nb]) {
			totsum += dist[nb] + cnt[nb];
			totcnt += cnt[nb];
		}

	totsum += pardist;
	totcnt += parcnt + 1;
	ans[node] = totsum;

	vis[node] = true;
	for (int nb : adj[node])
		if (!vis[nb]) {
			totcnt -= cnt[nb];
			totsum -= dist[nb] + cnt[nb];
			sumdist(nb,totsum+totcnt,totcnt);
			totsum += dist[nb] + cnt[nb];
			totcnt += cnt[nb];
		}
}

int main() {
	int n; cin>>n;
	adj.resize(n+1);
	for (int i=0;i<n-1;i++) {
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	sumdist(1,0,0);
	for (int i=1;i<=n;i++) cout << ans[i] << " ";
	return 0;
}