#include <bits/stdc++.h>
using namespace std;



void solve() {
	int n, m; cin>>n>>m;
	vector<int> bv(n);
	vector<vector<pair<int, int>>> adj(n);
	for (int& i : bv) cin>>i;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin>>a>>b>>c; a--; b--;
		int x = min(a,b), y = max(a,b);
		adj[x].push_back({y,c});
	}

	int lo = 0, hi = 1000000000, mid, ans = -1;

	while (lo <= hi) {
		mid = (lo + hi) / 2;
		vector<int> max_bat(n, -1);
		max_bat[0] = min(mid, bv[0]);
		for (int i=0;i<n;i++) {
			if (max_bat[i] == -1) continue;
			for (auto& [nb, w] : adj[i]) {
				if (max_bat[i] < w) continue;
				max_bat[nb] = max(max_bat[nb], min(mid, max_bat[i] + bv[nb]));
			}
		}

		if (max_bat[n - 1] >= 0) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	cout<<ans<<endl;

}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}