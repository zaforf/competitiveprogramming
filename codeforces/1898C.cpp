#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,m,k; cin>>n>>m>>k;
	if (k < n+m-2 || (k % 2 != (n + m) % 2)) {
		cout << "NO" << endl;
		return;
	}
	vector<vector<int>> rights(n, vector<int>(m-1));
	cout << "YES" << endl;
	for (int i=0;i<n;i++)
		for (int j=0;j<m-1;j++)
			rights[i][j] = j & 1;

	vector<vector<int>> downs(n-1, vector<int>(m));
	for (int i=0;i<n-1;i++)
		for (int j=0;j<m;j++)
			downs[i][j] = (i & 1) == (m & 1);

	int mod4 = (k - (n+m-2)) % 4;
	if (mod4 == 2) {
		downs[0][1] = 1;
		downs[1][0] = 1;
		rights[1][1] = 1;
		rights[2][1] = 1;
	}
	for (auto& v : rights) {
		for (auto x : v)
			if (x) cout << "B ";
			else cout << "R ";
		cout << endl;
	}
	for (auto& v : downs) {
		for (auto x : v)
			if (x) cout << "B ";
			else cout << "R ";
		cout << endl;
	}
	
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}