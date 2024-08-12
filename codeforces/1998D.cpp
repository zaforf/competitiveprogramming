#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,m; cin>>n>>m;
	vector<vector<int>> adj(n+1);
	vector<vector<int>> radj(n+1);
	for (int i=1;i<n;i++) adj[i].push_back(i+1);
	for (int i=0;i<m;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		radj[b].push_back(a);
	}
	vector<int> dist(n+1,-1);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int c = q.front(); q.pop();
		for (int nb : adj[c])
			if (dist[nb]==-1) {
				dist[nb] = dist[c]+1;
				q.push(nb);
			}
	}
	string ans = string(n-1,'1');
	// i = 0 if exists u->v where
	// v>=i && u<i is a bridge
	// s.t. dist[v] < v-i
	// i < v-dist[v] <- store max
	multiset<int> diffs;
	vector<vector<int>> begin(n+1);
	for (int i=n;i>0;i--) {
		for (int back : radj[i]) {
			int diff = i-(dist[back]+1);
			diffs.insert(diff);
			begin[back].push_back(diff);
		}	
		for (int rem : begin[i]) {
			diffs.erase(diffs.find(rem));
		}
		int mx = diffs.empty() ? -1 : *diffs.rbegin();
		if (i<mx) ans[i-1]='0';
	}
	cout << ans << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}