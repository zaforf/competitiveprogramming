#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;
vector<int> ord;
vector<vector<int>> adj,adj_t;
bool vis[MAXN];
int comp[MAXN], k=0;

void dfs(int x) {
	vis[x]=true;
	for (int nb : adj[x])
		if (!vis[nb])
			dfs(nb);
	ord.push_back(x);
}

void assign(int x) {
	comp[x] = k;
	for (int nb : adj_t[x])
		if (!comp[nb])
			assign(nb);
}

int main() {
	int n,m;cin>>n>>m;
	adj.resize(n+1);adj_t.resize(n+1);
	for (int i=0;i<m;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj_t[b].push_back(a);
	}
	for (int i=1;i<n;i++) {
		if (!vis[i])
			dfs(i);
	}
	reverse(ord.begin(),ord.end());
	for (int i : ord)
		if (!comp[i]) {
			k++;
			assign(i);
		}
	cout << k << "\n";
	for (int i=1;i<=n;i++)
		cout << comp[i] << " ";
	return 0;
}