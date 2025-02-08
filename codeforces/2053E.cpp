#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<array<int,4>>& info) {
	info[node][0] = 1;
	int adj_to_leaves = 0;
	for (int nb : adj[node])
		if (!info[nb][0]) {
			info[nb][3] = node;
			info[nb][1]++;
			dfs(nb,adj,info);
			info[node][1]++;
			if (info[nb][1] == 1) adj_to_leaves++;
			info[node][2] += info[nb][2];
		}
	if (info[node][1]>1 && !adj_to_leaves)
		info[node][2]++;
}

void dfs2(int node, vector<vector<int>>& adj, vector<array<int,4>>& info, long long* ans, int* start) {
	int adj_to_leaves = 0;
	for (int nb : adj[node]) {
		if (info[nb][3] == node) dfs2(nb, adj, info, ans, start);
		if (info[nb][1] == 1) adj_to_leaves++;
	}

	int k = info[node][1] - adj_to_leaves;
	if (adj_to_leaves && (k >= 2)) { // eligible
		for (int nb : adj[node]) {
			if (info[nb][1] > 1) { // non leaves
				if (info[nb][3] == node) { // down
					*ans += info[nb][2] * (k - 1);
				} else { // up
					*ans += (info[*start][2] - info[node][2]) * (k - 1);
				}
			}
		}
	}
}

void solve() {
	int n; cin>>n;
	vector<vector<int>> adj(n);
	vector<array<int,4>> info(n); // vis, deg, below, par
	vector<int> deg(n);
	for (int i=0;i<n-1;i++) {
		int a,b; cin>>a>>b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	long long ans = 0;
	int start = 0;
	while (start < n && deg[start] == 1) start++;
	if (start == n) {
		cout << "0\n";
		return;
	}
	info[start][3] = -1;
	dfs(start, adj, info);
	dfs2(start, adj, info, &ans, &start);
	long long leaves = 0ll;
	for (int i=0;i<n;i++) if (info[i][1] == 1) leaves++;
	cout << leaves * (n-leaves) + ans << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}