#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200001;
vector<int> adj[MAX_N];
int par[MAX_N];
int depth[MAX_N] = {-1};
int etime[MAX_N][2];
int t = 0;

void dfs(int node, int p) {
	par[node] = p;
	depth[node] = depth[p] + 1;
	etime[node][0] = t++;
	for (int nb : adj[node])
		if (nb != p)
			dfs(nb, node);
	etime[node][1] = t++;
}

int main() {
	int n, q; cin >> n >> q;
	for (int i=0;i<n-1;i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,1);
	for (int i=0;i<q;i++) {
		int mx = 0, mxd = -1;
		int qsize; cin >> qsize;
		vector<int> a(qsize);
		for (int j=0;j<qsize;j++) {
			int inp; cin>>inp;
			a[j] = par[inp];
			if (depth[inp] > mxd) {
				mxd = depth[inp];
				mx = inp;
			}
		}
		bool ok = true;
		for (int anc : a)
			ok &= etime[anc][0] <= etime[mx][0] && etime[mx][1] <= etime[anc][1];
		cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}