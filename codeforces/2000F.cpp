#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

const int MAX = 1e9;

void solve() {
	int n,k; cin>>n>>k;
	vector<vector<int>> dp(n+1,vector<int>(k+1,MAX));
	dp[0][0] = 0;
	for (int i=1;i<=n;i++) {
		int a,b;cin>>a>>b;
		vector<int> inc(a+b+1,MAX);
		inc[0] = 0;
		for (int x=0;x<=a;x++)
			for (int y=0;y<=b;y++)
				inc[x+y] = min(inc[x+y],x*b+y*a-x*y);
		for (int j=0;j<=k;j++) {
			for (int z=0;z<=a+b;z++) {
				if (j+z<=k) dp[i][j+z] = min(dp[i][j+z],dp[i-1][j]+inc[z]);
			}
		}
	}
	int ans = MAX;
	for (int i=1;i<=n;i++)
		ans = min(ans,dp[i][k]);
	cout << (ans==MAX?-1:ans) << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}