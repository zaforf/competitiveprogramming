#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

void dfs(int node, vector<vector<int>>& subtree, vector<vector<int>>& adj, vector<pii>& ans) {
	for (int sub : subtree[node]) {
		cout << "? " << node << " " << sub << endl;
		int res; cin>>res;
		if (res==node) {
			adj[node].push_back(sub);
			ans.push_back({node,sub});
		} else subtree[res].push_back(sub);
	}
	for (int nb : adj[node])
		dfs(nb,subtree,adj,ans);
}

void solve() {
	int n; cin>>n;
	vector<vector<int>> subtree(n+1);
	vector<vector<int>> adj(n+1);
	vector<pii> ans;
	for (int i = 2; i<=n;i++) {
		cout << "? 1 " << i << endl;
		int res; cin>>res;
		if (res==1) {
			adj[1].push_back(i);
			ans.push_back({1,i});
		} else subtree[res].push_back(i);
	}
	for (int nb : adj[1]) dfs(nb,subtree,adj,ans);
	cout << "! ";
	for (pii& a : ans) cout << a.f << " " << a.s << " ";
	cout << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}