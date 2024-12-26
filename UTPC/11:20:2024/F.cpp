#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main() {
	int n; cin>>n;
	vector<pair<int,int>> ps;
	for (int i=0;i<n;i++) {
		int a,b;cin>>a>>b;
		ps.push_back({a,b});
	}
	vector<vector<int>> dp(1<<n,vector<int>(n,1e9));
	for (int i=1,j=0;i<(1<<n); i<<=1,j++) {
		dp[i][j] = 0;
	}
	for (int i=1;i<(1<<n);i++) {
		for (int b=0;b<n;b++) {
			if (i&(1<<b)) {
				for (int j=0;j<n;j++) {
					if (b==j) continue;
					if ((i&(1<<j)) == 0) continue;
					int dx = ps[b].f - ps[j].f;
					int dy = ps[b].s - ps[j].s;
					dp[i][b] = min(dp[i][b],max(dp[i-(1<<b)][j],dx*dx+dy*dy));
				}
			}
		}
	}
	cout << min(2,n-1) << " " << *min_element(dp[(1<<n)-1].begin(),dp[(1<<n)-1].end());
	return 0;
}