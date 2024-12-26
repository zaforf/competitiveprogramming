#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<vector<int>> adj;
vector<int> in;

int dfs(int node) {
	vis[node] = true;
	int res = 0;
	if (in[node]==0) res++;
	for (int nb : adj[node])
		if (!vis[nb]) 
			res += dfs(nb);
	return res;
}

int main() {
	int n; cin>>n;
	adj.resize(n);
	in.resize(n);
	vis.resize(n);
	int ans = 0;
	for (int i=1;i<=n;i++) {
		int b; cin>>b;
		if (i==b) {
			vis[i-1] = 1;
			continue;
		}
		in[b-1]++;
		adj[i-1].push_back(b-1);
		adj[b-1].push_back(i-1);
	}
	for (int i=0;i<n;i++) {
		if (!vis[i])
			ans += max(1,dfs(i));
	}
	cout << n-ans;
	return 0;
}