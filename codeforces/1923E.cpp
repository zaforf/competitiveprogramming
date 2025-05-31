#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> adj;

long long ans;
vector<map<int,int>> cnt;

void dfs(int node, int p = -1) {
	int large = -1;
	for (int nb : adj[node]) if (nb != p) {
		dfs(nb, node);
		if (large == -1 || cnt[nb].size() > cnt[large].size())
			large = nb;
	}
	// found large, now merge and inc ans
	for (int nb : adj[node]) if (nb != p && nb != large) {
		for (auto& [color, freq] : cnt[nb]) {
			if (color != a[node]) ans += cnt[large][color] * 1ll * freq;
			cnt[large][color] += freq;
		}
	}
	if (large != -1) swap(cnt[node], cnt[large]);
	ans += cnt[node][a[node]];
	cnt[node][a[node]] = 1;
}

void solve() {
	cin >> n;
	a.resize(n); adj.assign(n, {});
	for (int& i : a) cin >> i;
	for (int i=0;i<n-1;i++) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 0;
	cnt.assign(n, {});
	dfs(0);
	cout << ans << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}