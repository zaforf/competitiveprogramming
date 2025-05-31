#include <bits/stdc++.h>
using namespace std;

void szs(int node, vector<vector<int>>& kids, vector<int>& sz) {
	int my_sz = 1;
	for (int nb : kids[node]) {
		szs(nb, kids, sz);
		my_sz += sz[nb];
	}
	sz[node] = my_sz;
}

int sol(int node, vector<vector<int>>& kids, vector<int>& sz) {
	int sum = 0, mx = 0, mx_nb = 0;
	for (int nb : kids[node]) {
		sum += sz[nb];
		if (sz[nb] > mx) {
			mx = sz[nb];
			mx_nb = nb;
		}
	}
	if (2*mx <= sum)
		return sum - (sum&1);
	// cout << " mx " << mx << " sum " << sum << endl;
	int excess = 2*mx - sum;
	int resolvable = sol(mx_nb, kids, sz);
	// cout << "excess " << excess << " but resolvable is " << resolvable << endl;
	return sum - max(excess-resolvable,0);
}

void solve() {
	int n; cin>>n;
	vector<vector<int>> kids(n);
	for (int i=0;i<n-1;i++) {
		int inp; cin>>inp;
		kids[inp-1].push_back(i+1);
	}
	vector<int> sz(n);
	szs(0, kids, sz);
	cout << sol(0, kids, sz)/2 << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}