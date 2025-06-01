#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin>>u>>v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<array<int,3>> ans;
	vector<bool> vis(n);
		// find max depth, and among those with max depth, the max index
	function<pair<int,int>(int)> dfs = [&](int node) -> pair<int, int> {
		vis[node] = true;
		int max_depth = 0, max_index = node;
		for (int nei : adj[node]) {
			if (!vis[nei]) {
				auto [depth, index] = dfs(nei);
				if (depth > max_depth || (depth == max_depth && index > max_index)) {
					max_depth = depth;
					max_index = index;
				}
			}
		}
		vis[node] = false;
		return {max_depth + 1, max_index};
	};

	// mark nodes on the path from a to b as visited
	function<bool(int,int)> mark_path = [&](int a, int b) {
		vis[a] = true;
		if (a == b) return true;
		for (int nei : adj[a]) {
			if (!vis[nei] && mark_path(nei, b)) {
				vis[a] = true;
				return true;
			}
		}
		vis[a] = false;
		return false;
	};

	for (int i=0;i<n;i++) {
		while (!vis[i]) {
			auto [trash, start_index] = dfs(i);
			auto [depth, index] = dfs(start_index);
			ans.push_back({depth, max(start_index, index)+1, min(start_index, index)+1});
			mark_path(start_index, index);
		}
	}
	sort(ans.begin(), ans.end(), greater<array<int,3>>());
	for (auto& [depth, u, v] : ans) {
		cout << depth << " " << u << " " << v << " ";
	}
	cout << "\n";
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}