#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
bool vis[MAXN],instack[MAXN];
vector<vector<int>> adj;
vector<int> cycle;

bool dfs(int node) {
	vis[node] = instack[node] = true;
	for (int nb : adj[node])
		if (instack[nb]) {
			instack[nb] = instack[node] = false;
			cycle.push_back(node);
			return true;
		} else if (!vis[nb]) {
			if (dfs(nb)) {
				if (instack[node]) {
					instack[node]=false;
					cycle.push_back(node);
					return true;
				} else {
					cycle.push_back(node);
					return false;
				}
			}
			if (!cycle.empty())
				return false;
		}
	instack[node]=false;
	return false;
}

int main() {
	int N,M;cin>>N>>M;
	adj.resize(N+1);
	for (int i=0;i<M;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
	}
	for (int i=1;cycle.empty() && i<N+1;i++) dfs(i);
	if (cycle.empty()) cout<<"IMPOSSIBLE";
	else {
		reverse(begin(cycle),end(cycle));
		cout<<cycle.size()+1<<"\n";
		cout<<cycle.back();
		for (auto a : cycle)
			cout<<" "<<a;
	}
	return 0;
}