#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<vector<int>> adj;
vector<bool> vis;

bool check(int i) {
	vis[i] = 1;
	for (int nb : adj[i]) {
		if (vis[nb]) continue;
		if (a[nb]%2) {
			vis[nb] = 1;
			return true;
		}
	}
	return false;
}

int main() {
	int n; cin>>n;
	a.resize(n);
	vis.resize(n);
	adj.resize(n);
	for (int& i : a) cin>>i;
	for (int i=0;i<n-1;i++) {
		int x,y;cin>>x>>y;x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int ans = 0;
	for (int i=0;i<n;i++) {
		if (a[i]%2) {
			if (vis[i]) continue;
			if (check(i)) ans++;
			else {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	for (int v : a)
		if (v%2==0) ans++;
	cout << ans;
	return 0;
}