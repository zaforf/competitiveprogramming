#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

bool used[(1<<16)+1];
vector<vector<pair<pii,int>>> adj;
vector<int> ans;

void dfs(int x) {
	while (adj[x].size()) {
		pair<pii,int> p = adj[x].back();
		adj[x].pop_back();
		if (!used[p.s]) {
			used[p.s] = true;
			ans.push_back(p.f.s);
			dfs(p.f.f);
		}
	}
}

int main() {
	int n;cin>>n;
	if (n==1) { cout << "10"; return 0; }
	adj.resize(1<<(n-1));
	int ind=0;
	for (int i=0;i<1<<(n-1);i++)
		for (int j=0;j<1<<(n-1);j++)
			if ((i&(i^(1<<(n-2))))==j>>1) {
				adj[i].push_back({{j,j&1},ind++});
			}
	dfs(0);
	for (int i=0;i<n-1;i++) cout<<"0";
	for (int i : ans) {
		cout << i;
	}
	return 0;
}