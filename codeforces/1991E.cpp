#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin>>n>>m;
	vector<vector<int>> adj(n);
	for (int i=0;i<m;i++) {
		int a, b; cin>>a>>b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> dist(n,-1);
	vector<int> even, odd;
	queue<int> q;
	q.push(0);
	int d = 0;
	bool two_colorable = true;
	while (q.size()) {
		int sz = q.size();
		for (int i=0;i<sz;i++) {
			int c = q.front(); q.pop();
			if (dist[c] != -1) {
				if (dist[c] == d) continue;
				else {
					two_colorable = false;
					break;
				}
			}
			if (d % 2) odd.push_back(c);
			else even.push_back(c);
			dist[c] = d;
			for (int nb : adj[c])
				if (dist[nb]==-1)
					q.push(nb);
		}
		if (!two_colorable) break;
		d++;
	}
	if (!two_colorable) {
		cout << "Alice" << endl;
		for (int i=0;i<n;i++) {
			cout << "1 2" << endl;
			cin >> d >> d;
		}
	} else {
		cout << "Bob" << endl;
		int v1, v2, non_three;
		int three_is = even.empty() ? 1 : (odd.empty() ? 2 : 0);
		int empty = even.empty() ? 2 : (odd.empty() ? 1 : 0);
		for (int i=0;i<n;i++) {
			cin>>v1>>v2;
			if (!three_is) {
				non_three = v1 == 3 ? v2 : v1;
				int node;
				if (non_three == 1) {
					node = odd.back();
					odd.pop_back();
				} else {
					node = even.back();
					even.pop_back();
				}
				cout << node+1 << " " << non_three << endl;
				three_is = even.empty() ? 1 : (odd.empty() ? 2 : 0);
			} else {
				empty = even.empty() ? 2 : (odd.empty() ? 1 : 0);
				non_three = v1 == empty ? v2 : v1;
				int node;
				if (three_is == 1) {
					node = odd.back();
					odd.pop_back();
				} else {
					node = even.back();
					even.pop_back();
				}
				cout << node+1 << " " << non_three << endl;
			}
		}
	}
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}