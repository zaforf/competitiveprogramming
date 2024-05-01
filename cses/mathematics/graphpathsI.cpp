#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int MOD=1e9+7;
 
vector<vector<int>> operator*(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	// a = n*w, b = w*m;
	int n=a.size(),w=a[0].size(),m=b.size();
	vector<vector<int>> res(n, vector<int>(m,0));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			for (int k=0;k<w;k++)
				res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % MOD;
	return res;
}
 
vector<vector<int>> exp(vector<vector<int>> a, int b) {
	int n=a.size();
	vector<vector<int>> res(n,vector<int>(n,0));
	for (int i=0;i<n;i++) res[i][i]=1;
	while (b>0) {
		if (b&1) res = res * a;
		a=a*a; b >>= 1;
	}
	return res;
}
 
int32_t main() {
	int n,m,k;cin>>n>>m>>k;
	vector<vector<int>> adj(n,vector<int>(n,0));
	for (int i=0;i<m;i++) {
		int a,b;cin>>a>>b;a--;b--;
		adj[a][b]++;
	}
	cout << exp(adj,k)[0][n-1];
	return 0;
}
