#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<long long> paths;
vector<bool> vis;

int dfs(int n) {
	vis[n]=true;
	for (int nb : adj[n]) {
		if (!vis[nb])
			paths[n]+=dfs(nb);
	}
	if (paths[n]==0) paths[n]++;
	return paths[n];
}

void solve() {
	int N;cin>>N;
	adj.clear();adj.resize(N+1);
	paths.clear();paths.resize(N+1);
	vis.clear();vis.resize(N+1);
	for (int i=0;i<N-1;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	int Q;cin>>Q;
	while (Q--) {
		int a,b;cin>>a>>b;
		cout<<paths[a]*paths[b]<<"\n";
	}
}

int main() {
	int T;cin>>T;
	while (T--)
		solve();
	return 0;
}