#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

const int MAXN = 1002;
int adj[MAXN][MAXN];

vector<vector<int>> edges;
int n,m,k;
int ans;

int main() {
	cin>>n>>m>>k; edges.resize(m+502);
	for (int i=0;i<k;i++) {
		int a,b;cin>>a>>b; b += 500;
		adj[a][b]=1;
		if (!adj[0][a]) edges[0].push_back(a);
		if (!adj[b][m+501]) edges[b].push_back(m+501);
		adj[0][a]=1; adj[b][m+501]=1;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<int> par(m+502,-1);
	while (true) {
		queue<int> q;
		fill(par.begin(),par.end(),-1);
		q.push(0);
		while (!q.empty()) {
			int c = q.front(); q.pop();
			if (c==m+501) break;
			for (int nb : edges[c]) {
				if (adj[c][nb] && par[nb]==-1) {
					par[nb] = c;
					q.push(nb);
				}
			}
		}
		if (par[m+501]==-1) break;
		int c = m+501;
		while (c != 0) {
			adj[par[c]][c] -= 1;
			adj[c][par[c]] += 1;
			c = par[c];
		}
		ans += 1;
		
	}
	queue<int> q; vector<pii> pairs;
	fill(par.begin(),par.end(),-1);
	q.push(0);
	while (!q.empty()) {
		int c = q.front(); q.pop();
		for (int nb : edges[c]) {
			if (par[nb] != -1) continue;
			if (!adj[c][nb]) {
				if (nb>500) pairs.push_back({c,nb-500});
				else q.push(nb);
				par[nb] = c;
			}
		}
	}
	cout << ans << '\n';
	for (pii p : pairs) cout << p.f << " " << p.s << '\n';
	return 0;
}