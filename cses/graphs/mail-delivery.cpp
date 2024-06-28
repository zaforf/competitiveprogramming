#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

const int MAXM = 2e5+1;
bool used[MAXM];
int n,m;
vector<vector<pii>> adj;
vector<int> ans;
  
void dfs(int x) {
	while (adj[x].size()) {
		pii p = adj[x].back();
		adj[x].pop_back();
		if (!used[p.s]) {
			used[p.s] = true;
			dfs(p.f);
		}
	}
	// path guaranteed to have returned to x by here
	ans.push_back(x);
}

int main() {
	cin>>n>>m;
	adj.resize(n+1);
	for (int i=0;i<m;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back({b,i});
		adj[b].push_back({a,i});
	}
	bool bad = false;
	for (int i=1;i<=n;i++)
		bad |= adj[i].size()%2==1;
	if (bad)
		cout<<"IMPOSSIBLE";
	else {
		dfs(1);
		if (ans.size() != m+1)
			cout << "IMPOSSIBLE";
		else
			for (int i : ans)
				cout << i << " ";
	}
	return 0;

}