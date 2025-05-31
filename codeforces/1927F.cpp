#include <bits/stdc++.h>
using namespace std;

vector<int> e(200001);

int get(int x) { return (e[x]<0 ? x : e[x]=get(e[x])); }

bool merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a==b) return false;
	if (e[a]>e[b]) swap(a,b);
	e[a] += e[b];
	e[b] = a;
	return true;
}

int sz(int x) {return -e[get(x)];}

void find_cycle(int node, int find1, int find2, vector<int>& prev, vector<vector<int>>& adj) {
	for (int nb : adj[node]) {
		if (node == find1 && nb == find2) continue;
		if (!prev[nb]) {
			prev[nb] = node;
			find_cycle(nb, find1, find2, prev, adj);
		}
	}
}

void solve() {
	int n,m; cin>>n>>m;
	for (int i=1;i<=n;i++) e[i] = -1;
	vector<vector<int>> adj(n+1);
	priority_queue<array<int,3>> pq;
	for (int i=0;i<m;i++) {
		int a, b, w; cin>>a>>b>>w;
		adj[a].push_back(b);
		adj[b].push_back(a);
		pq.push({w,a,b});
	}
	array<int,3> best, curr;
	while (!pq.empty()) {
		curr = pq.top(); pq.pop();
		if (!merge(curr[1], curr[2]))
			best = curr;
	}
	vector<int> prev(n+1);
	prev[best[1]] = best[2];
	find_cycle(best[1], best[1], best[2], prev, adj);
	vector<int> ans;
	int p = best[2];
	do {
		ans.push_back(p);
		p = prev[p];
	} while (p != best[2]);
	cout << best[0] << " " << ans.size() << endl;
	for (int x : ans)
		cout << x << " ";
	cout << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}