#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

vector<vector<pii>> adj;
vector<int> path;
bool vis[501];
int ans=0,c=0,n,m;

int dfs(int x) {
	if (x==n) return 1e9+1;
	vis[x]=true;
	int minw=0;
	for (pii nb : adj[x]) {
		if (nb.s==0 || nb.s<c || vis[nb.f]) continue;
		cout << x << " dfs to " << nb.f << " "<<nb.s <<endl;
		int res = dfs(nb.f);
		if (res>0) minw=min(nb.s,res);
		path.push_back(nb.f);
		break;
	}
	vis[x]=false;
	return minw;
}

void reduce(int minw) {
	int i=0,x=1;
	while (x!=n) {
		for (pii nb : adj[x]) {
			if (nb.f==path[i]) {
				nb.s-=minw;
				cout << "edge from " << x <<" " << nb.f <<" to "<<nb.s << endl;
				// for (pii back : adj[nb.f])
				// 	if (back.f==x) {
				// 		back.s+=minw;
				// 		break;
				// 	}
				x = nb.f; i++;
				break;
			}
		}
	}
}

int main() {
	cin>>n>>m;
	adj.resize(n+1);
	for (int i=0;i<m;i++) {
		int a,b,w;cin>>a>>b>>w;
		c = max(c,w);
		adj[a].push_back({b,w});
		adj[b].push_back({a,0});
	}
	while (true) {
		int f = dfs(1);
		while (f>0) {
			ans += f;
			reverse(path.begin(),path.end());
			reduce(f);
			cout << " done reducing " << endl;
			path.clear();
			f = dfs(1);
		}
		if (c==0) break;
		else c/=2;
	}
	cout << ans;
	return 0;
}