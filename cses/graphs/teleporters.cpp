#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;
int in[MAXN]={0},out[MAXN]={0};
vector<vector<int>> adj;
vector<int> ans;
  
void dfs(int x) {
	while (adj[x].size()) {
		int nb = adj[x].back();
		adj[x].pop_back();
		dfs(nb);
	}
	ans.push_back(x);
}

int main() {
	int n,m;cin>>n>>m;
	adj.resize(n+1);
	for (int i=0;i<m;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		out[a]++;
		in[b]++;
	}
	bool bad = false;
	for (int i=2;i<n && !bad;i++)
		bad = (in[i]!=out[i]);
	if (bad || out[1]!=in[1]+1 || in[n]!=out[n]+1)
		cout<<"IMPOSSIBLE";
	else {
		dfs(1);
		reverse(ans.begin(),ans.end());
		if (ans.size() != m+1)
			cout << "IMPOSSIBLE";
		else
			for (int i : ans)
				cout << i << " ";
	}
	return 0;

}