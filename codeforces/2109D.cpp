#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000000001;

void solve() {
	int n,m,l; cin>>n>>m>>l;
	vector<int> a(l); int inp;
	int min_odd = MAX, sum = 0;
	for (int i=0;i<l;i++) {
		cin>>inp;
		sum += inp;
		if (inp & 1)
			min_odd = min(min_odd, inp);
	}
	vector<vector<int>> adj(n+1);
	for (int i=0;i<m;i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<pair<int,int>> q;
	q.push({1, 0});
	vector<vector<int>> dist(n+1, vector<int>(2,MAX));
	dist[1][0] = 0;
	int d = 0;
	while (q.size()) {
		int sz = q.size();
		for (int i=0;i<sz;i++) {
			auto [node, parity] = q.front(); q.pop();
			for (int nb : adj[node]) {
				if (dist[nb][parity^1] == MAX) {
					dist[nb][parity^1] = d + 1;
					q.push({nb, parity^1});
				}
			}
		}
		d++;
	}
	int mx_even_s, mx_odd_s;
	if (sum & 1) {
		mx_odd_s = sum;
		mx_even_s = sum - min_odd;
	} else {
		mx_even_s = sum;
		if (min_odd == MAX)
			mx_odd_s = 0;
		else
			mx_odd_s = sum - min_odd;
	}
	for (int i=1;i<=n;i++)
		cout << ((mx_even_s >= dist[i][0]) | (mx_odd_s >= dist[i][1]));
	cout << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}