#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second

const int MAXC = 1e9+1, MAXN = 501;
ll adj[MAXN][MAXN];
vector<vector<int>> edges;
bool vis[MAXN];
int n,m;
ll ans;

int main() {
	cin>>n>>m; edges.resize(n+1);
	for (int i=0;i<m;i++) {
		int a,b,w;cin>>a>>b>>w;
		adj[a][b] += w;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<int> par(n+1,-1);
	while (true) {
		queue<pii> q;
		fill(par.begin(),par.end(),-1);
		par[1] = 1; q.push({1,MAXC});
		int ret=0;
		while (!q.empty()) {
			int c; ll w;
			tie(c,w) = q.front();q.pop();
			if (c==n) {
				ret = w;
				break;
			}
			for (int nb : edges[c])
				if (adj[c][nb] && par[nb]==-1) {
					par[nb] = c;
					q.push({nb,min(w,adj[c][nb])});
				}
		}
		if (!ret) break;
		int c = n;
		while (c != 1) {
			adj[par[c]][c] -= ret;
			adj[c][par[c]] += ret;
			c = par[c];
		}
		ans += ret;
	}
	cout << ans;
	return 0;
}