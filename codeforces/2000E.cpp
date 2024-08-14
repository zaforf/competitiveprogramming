#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n,m,c; cin>>n>>m>>c;
	vector<vector<int>> grid(n+1,vector<int>(m+1));
	int g; cin>>g;
	vector<int> gs(g); for (int& i : gs) cin>>i;
	for (int i=0;i<n-c+1;i++)
		for (int j=0;j<m-c+1;j++) {
			grid[i][j]++;
			grid[i][j+c]--;
			grid[i+c][j]--;
			grid[i+c][j+c]++;
		}
	vector<int> muls;
	for (int i=0;i<n+1;i++) {
		for (int j=0;j<m+1;j++) {
			if (i) grid[i][j] += grid[i-1][j];
			if (j) grid[i][j] += grid[i][j-1];
			if (i && j) grid[i][j] -= grid[i-1][j-1];
			if (i<n && j<m) muls.push_back(grid[i][j]);
		}
	}
	sort(muls.begin(),muls.end(),greater<int>());
	sort(gs.begin(),gs.end(),greater<int>());
	int ans = 0;
	for (int i=0;i<g;i++)
		ans += gs[i]*muls[i];
	cout << ans << '\n';
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}