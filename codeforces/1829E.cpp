#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> vis;
vector<vector<int>> depth;

int dfs(int a,int b) {
	if (a<0 || b<0 || a>=vis.size() || b>=vis[0].size() || vis[a][b] || !depth[a][b])
		return 0;
	vis[a][b]=true;
	int ret = depth[a][b];
	ret += dfs(a-1,b);
	ret += dfs(a+1,b);
	ret += dfs(a,b-1);
	ret += dfs(a,b+1);
	return ret;
}

void solve() {
	int N,M;cin>>N>>M;
	vis.clear();vis.resize(N,vector<bool>(M,false));
	depth.clear();depth.resize(N,vector<int>(M));
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			cin>>depth[i][j];
	int ans=0;
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			if (depth[i][j] && !vis[i][j])
				ans = max(ans,dfs(i,j));
	cout<<ans<<"\n";
}



int main() {
	int T;cin>>T;
	while (T--)
		solve();
	return 0;
}