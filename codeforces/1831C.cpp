#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
vector<pair<int,int>> dp;


void dfs(int i) {
	for (auto nb : adj[i]) {
		if (dp[nb.first].second!=-1 || nb.first==1) continue;
		if (nb.second>dp[i].second) {
			dp[nb.first].first=dp[i].first;
		} else {
			dp[nb.first].first=dp[i].first+1;
		}
		dp[nb.first].second=nb.second;
		dfs(nb.first);
	}
}

void solve() {
	int N;cin>>N;
	dp.clear();dp.resize(N+1,{1,-1}); // readings, index of edge when read
	adj.clear();adj.resize(N+1); // nb, index of edge
	for (int i=0;i<N-1;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back({b,i});
		adj[b].push_back({a,i});
	}
	dfs(1);
	int ans=0;
	for (auto a : dp) {
		cout<<a.first<<" "<<a.second<<"\n";
		ans=max(ans,a.first);
	}
	cout<<ans<<"\n";
}

int main() {
	int T; cin>>T;
	while (T--)
		solve();
	return 0;
}