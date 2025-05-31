#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> f(n + 1), c(n + 1), indeg(n + 1);
	multiset<pair<int, int>> edges;
	vector<int> ans;

	for (int i = 1; i <= n; ++i) cin >> f[i];
	for (int i = 1; i <= n; ++i) cin >> c[i];
	for (int i = 1; i <= n; ++i) {
		indeg[f[i]]++;
		edges.insert({c[i], f[i]});
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (indeg[i] == 0)
			q.push(i);

	auto push = [&]() {
		while (!q.empty()) {
			int curr = q.front(); q.pop();
			ans.push_back(curr);
			auto it = edges.find({c[curr], f[curr]});
			if (it != edges.end())
				edges.erase(it);
			int to = f[curr];
			if (--indeg[to] == 0) {
				q.push(to);
			}
		}
	};

	push();

	while (!edges.empty()) {
		auto [cost, node] = *edges.begin();
		indeg[node]--;
		edges.erase(edges.begin());
		q.push(node);
		push();
	}

	for (int x : ans)
		cout << x << " ";
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) solve();
}
