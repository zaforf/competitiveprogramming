#include <bits/stdc++.h>
using namespace std;

void tortoise_hare(int p, vector<int>& func, vector<bool>& vis, vector<int>& loop) {
	int t = p, h = p;
	do {
		t = func[t];
		h = func[func[h]];
	} while (t != h);
	h = func[h];

	while (h != t) {
		loop.push_back(h);
		h = func[h];
	}
	loop.push_back(h);
}

void vis_all(int p, vector<bool>& vis, vector<vector<int>>& adj) {
	vis[p] = 1;
	for (int nb : adj[p])
		if (!vis[nb])
			vis_all(nb,vis,adj);
}

int ans = 0;

int dfs(int p, vector<vector<int>>& adj, vector<bool>& vis, int d) {
	int amt = 1;
	vis[p] = 1;
	for (int nb : adj[p]) {
		if (!vis[nb]) {
			amt += dfs(nb,adj,vis,d+1);
		}
	}
	if (d) ans = max(ans, amt);
	return amt;
}

void solve() {
	int n; cin>>n;
	vector<int> func(n+1);
	vector<vector<int>> adj(n+1);
	ans = 0;
	for (int i=1;i<=n;i++) {
		int b; cin >> b;
		func[i] = b;
		adj[i].push_back(b);
		adj[b].push_back(i);
	}
	vector<bool> vis(n+1);
	vector<int> loop;
	for (int i=1;i<=n;i++) {
		if (!vis[i]) {
			tortoise_hare(i,func,vis,loop);
			vis_all(loop.back(),vis,adj);
		}
	}
	fill(vis.begin(),vis.end(),0);
	for (int l : loop)
		vis[l] = 1;
	for (int l : loop)
		dfs(l, adj, vis, 0);
	cout << ans+2 << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}