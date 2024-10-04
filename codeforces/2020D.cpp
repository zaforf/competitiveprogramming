#include <bits/stdc++.h>
using namespace std;

vector<int> e(200001);

int get(int x) { return (e[x]<0 ? x : e[x]=get(e[x])); }

bool merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a==b) return false;
	if (e[a]>e[b]) swap(a,b);
	e[a] += e[b];
	e[b] = a;
	return true;
}

int sz(int x) {return -e[get(x)];}

void solve() {
	int n,m; cin>>n>>m;
	vector<vector<int>> dp(n+1,vector<int>(11,0));
	for (int i=0;i<m;i++) {
		int a,d,k;cin>>a>>d>>k;
		dp[a][d] = max(dp[a][d],k);
	}
	int tot = 0;
	for (int i=1;i<=n;i++) e[i]=-1;

	for (int i=1;i<=n;i++) {
		for (int j=1;j<=10;j++) {
			if (i-j > 0 && dp[i-j][j]>0) {
				dp[i][j] = max(dp[i][j],dp[i-j][j]-1);
				merge(i,i-j);
			}
		}
	}

	for (int i=n;i>0;i--) {
		for (int j=1;j<=10;j++) {
			if (dp[i][j] && i+j<=n)
				merge(i,i+j);
		}
	}

	for (int i=1;i<=n;i++)
		tot += e[i]<0;
	cout << tot << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}