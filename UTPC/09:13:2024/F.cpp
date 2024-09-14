#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,m,s,k,g; cin>>n>>m>>s>>k>>g;
	vector<vector<int>> adj(n+1);
	for (int i=0;i<m;i++) {
		int a,b; cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> q;
	vector<bool> exit(n+1), ghost(n+1);
	for (int i=0;i<k;i++) {
		int inp; cin>>inp;
		exit[inp] = true;
	}
	for (int i=0;i<g;i++) {
		int inp; cin>>inp;
		q.push(inp);
	}
	vector<int> vis(n+1,1e9);
	int dist = 0;
	while (q.size()) {
		int sz = q.size();
		for (int i=0;i<sz;i++) {
			int c = q.front(); q.pop();
			if (vis[c]<dist) continue;
			vis[c] = dist;
			for (int nb : adj[c]) {
				if (vis[nb]>=dist)
					q.push(nb);
			}
		}
		dist++;
	}
	vector<int> fromboy(n+1,1e9);
	q.push(s); dist = 0;
	while (q.size()) {
		int sz = q.size();
		for (int i=0;i<sz;i++) {
			int c = q.front(); q.pop();
			if (fromboy[c]<dist) continue;
			fromboy[c] = dist;
			for (int nb : adj[c]) {
				if (fromboy[nb]>=dist)
					q.push(nb);
			}
		}
		dist++;
	}
	int ans = 0;
	for (int i=1;i<n+1;i++) {
		if (exit[i] && fromboy[i] < vis[i]) ans++;
	}
	cout << ans << endl;
	
}

int main() {
	// int T;cin>>T;
	// while (T --> 0) {
		solve();
	// }
	return 0;
}