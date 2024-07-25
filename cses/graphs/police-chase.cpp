#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

const int MAXN = 501;
int adj[MAXN][MAXN], og[MAXN][MAXN];

vector<vector<int>> edges;
int n,m;
int ans;

int main() {
	cin>>n>>m; edges.resize(n+1);
	for (int i=0;i<m;i++) {
		int a,b;cin>>a>>b;
		adj[a][b]++; adj[b][a]++;
		og[a][b]++; og[b][a]++;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<int> par(n+1);
	while (true) {
		queue<pii> q;
		fill(par.begin(),par.end(),0);
		par[1] = 1; q.push({1,2});
		int ret = 0;
		while (!q.empty()) {
			int c, w;
			tie(c,w) = q.front();q.pop();
			if (c==n) {
				ret = w;
				break;
			}
			for (int nb : edges[c])
				if (adj[c][nb] && !par[nb]) {
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
	queue<int> q; vector<pii> rem;
	fill(par.begin(),par.end(),0);
	par[1]=1; q.push(1);
	while (!q.empty()) {
		int c = q.front(); q.pop();
		for (int nb : edges[c]) {
			if (par[nb]) continue;
			if (adj[c][nb]) {
				q.push(nb);
				par[nb] = c;
			}
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (par[i] && !par[j] && og[i][j]) rem.push_back({i,j});
	cout << ans << '\n';
	for (pii p : rem) cout << p.f << " " << p.s << '\n';
	return 0;
}