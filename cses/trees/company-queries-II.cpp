#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5+1;
int depth[MAXN], lift[MAXN][18];
vector<vector<int>> adj;
 
void dfs(int node, int d) {
	depth[node] = d;
	for (int nb : adj[node])
		dfs(nb,d+1);
}
 
int kthparent(int x, int d) {
	int k=0;
	while (d) {
		if (x == -1) break;
		if (d&1) x = lift[x][k];
		d >>= 1;
		k++;
	}
	return x;
}
 
int main() {
	int n,q; cin>>n>>q;
	adj.resize(n+1);
	for (int i=2;i<=n;i++) {
		cin >> lift[i][0];
		adj[lift[i][0]].push_back(i);
	}
 
	lift[1][0] = -1;
	for (int k=1;k<18;k++) {
		for (int i=1;i<=n;i++) {
			int par = lift[i][k-1];
			if (par == -1) lift[i][k] = -1;
			else lift[i][k] = lift[par][k-1];
		}
	}
 
	dfs(1,0);
 
	while (q --> 0) {
		int a,b; cin>>a>>b;
		if (depth[a]>depth[b]) swap(a,b);
		b = kthparent(b,depth[b]-depth[a]);
		if (a==b) cout << a << '\n';
		else {
			for (int i=17;i>=0;i--) {
				if (lift[a][i]!=lift[b][i]) {
					a = lift[a][i];
					b = lift[b][i];
				}
			}
			cout << lift[a][0] << '\n';
		}
	}
	return 0;
}