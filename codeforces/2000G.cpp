#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,m; cin>>n>>m;
	int t0, t1, t2; cin>>t0>>t1>>t2;
	vector<vector<array<int,3>>> adj(n+1);
	for (int i=0;i<m;i++) {
		int a,b,c,d; cin>>a>>b>>c>>d;
		adj[a].push_back({b,c,d});
		adj[b].push_back({a,c,d});
	}
	vector<int> dist(n+1,-1);
	dist[n] = t0;
	priority_queue<pair<int,int>> s;
	s.push({dist[n],n});
	auto put = [&](int t, int to) {
		if (t>dist[to]) {
			dist[to] = t;
			s.emplace(dist[to],to);
		}
	};
	while (!s.empty()) {
		auto [t,v] = s.top(); s.pop();
		if (t!=dist[v]) continue;
		for (auto& [nb,b,w] : adj[v]) {
			put(t-w,nb);
			if (t<=t1 || t2<=t-b)
				put(t-b,nb);
			else
				put(t1-b,nb);
		}
	}
	cout << dist[1] << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}