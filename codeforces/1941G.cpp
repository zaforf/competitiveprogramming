#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin>>n>>m;
	set<pair<int,int>> edges;
	for (int i=0;i<m;i++) {
		int a, b, c; cin>>a>>b>>c;
		edges.insert({a,c});
		edges.insert({b,c});
	}

}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}