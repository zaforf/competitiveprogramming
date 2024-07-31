#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

const int MAXN = 2e5+1;
bool vis[MAXN];
bool leaf[MAXN];
int ans = 0;
vector<vector<int>> adj;

void dfs(int node) {
	vis[node] = true;
	leaf[node] = true;
	for (int nb : adj[node])
		if (!vis[nb]) {
			leaf[node] = false;
			dfs(nb);
		}
	vis[node] = false;
}

pii match(int node) {
	// returns {# if node matched down, # if node matched up}
	// in subtree
	if (leaf[node]) return {0,0};
	int total = 0, diff = -1;
	vis[node] = true;
	for (int nb : adj[node])
		if (!vis[nb]) {
			auto [a,b] = match(nb);
			total += a;
			diff = max(diff,-a+b);
		}
	return {total+diff+1,total};
}		

int main() {
	int n; cin>>n;
	adj.resize(n+1);
	for (int i=0;i<n-1;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cout << match(1).f;
	return 0;
}