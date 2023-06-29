#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,M;cin>>N>>M;
	vector<vector<pair<int,int>>> adj(N+1); // weight, node
	for (int i=0;i<M;i++) {
		int a,b,w;cin>>a>>b>>w;
		adj[a].push_back({w,b});
		adj[b].push_back({w,a});
	}
	using T = pair<long long,int>;
	priority_queue<T, vector<T>, greater<T>> q;
	vector<long long> dist(N+1,LLONG_MAX);
	vector<int> from(N+1);
	q.push({0,1});
	dist[1]=0;

	while (!q.empty()) {
		long long cdist; int p;
		tie(cdist,p) = q.top();
		q.pop();
		if (cdist!=dist[p]) continue;
		for (pair<int,int> nb : adj[p]) { // dist, node
			if (cdist+nb.first<dist[nb.second]) {
				q.push({dist[nb.second]=dist[p]+nb.first,nb.second});
				from[nb.second]=p;
			}
		}
	}

	if (dist[N]==LLONG_MAX)
		cout<<-1;
	else {
		int x = N;
		vector<int> ans = {N};
		while (from[x])
			ans.push_back(x=from[x]);
		reverse(begin(ans),end(ans));
		for (auto a : ans) cout<<a<<" ";
	}
	return 0;
}