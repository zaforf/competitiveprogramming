#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
bool vis[MAXN];
vector<int> ans;
vector<vector<int>> adj;

void dfs(int i) {
	vis[i]=true;
	for (int nb : adj[i])
		if (!vis[nb])
			dfs(nb);
	ans.push_back(i);
}

int main() {
	int N,M;cin>>N>>M;
	adj.resize(N+1);
	for (int i=0;i<M;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
	}
	for (int i=1;i<N+1;i++)
		if (!vis[i])
			dfs(i);
	reverse(begin(ans),end(ans));
	vector<int> ind(N+1);
	for (int i=0;i<N;i++) ind[ans[i]]=i;
	for (int i=1;i<N+1;i++)
		for (int nb : adj[i]) {
			if (ind[nb]<=ind[i]) {
				cout<<"IMPOSSIBLE";
				return 0;
			}
		}
	for (int a : ans) cout<<a<<" ";
	return 0;
}