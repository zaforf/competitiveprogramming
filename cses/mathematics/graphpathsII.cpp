#include <bits/stdc++.h>
using namespace std;
#define int long long

 
vector<vector<int>> operator*(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	// a = n*w, b = w*m;
	int n=a.size(),w=a[0].size(),m=b.size();
	vector<vector<int>> res(n, vector<int>(m,-1));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			for (int k=0;k<w;k++) {
				if (a[i][k]==-1 || b[k][j]==-1) continue;
				if (res[i][j]==-1)
					res[i][j] = a[i][k]+b[k][j];
				else
					res[i][j] = min(res[i][j],a[i][k]+b[k][j]);
			}
	return res;
}
 
vector<vector<int>> exp(vector<vector<int>> a, int b) {
	int n=a.size();
	vector<vector<int>> res(n,vector<int>(n,-1));
	res[0][0]=0;
	while (b>0) {
		if (b&1) res = res * a;
		a=a*a; b >>= 1;
	}
	return res;
}
 
int32_t main() {
	int n,m,k;cin>>n>>m>>k;
	vector<vector<int>> adj(n,vector<int>(n,-1));
	for (int i=0;i<m;i++) {
		int a,b,w;cin>>a>>b>>w;a--;b--;
		if (adj[a][b]==-1) adj[a][b]=w;
		else adj[a][b]=min(adj[a][b],w);
	}
	cout << exp(adj,k)[0][n-1];
	return 0;
}
