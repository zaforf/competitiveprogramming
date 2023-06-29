#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,M;cin>>N>>M;
	vector<vector<int>> adj(N+1);
	vector<int> parent(N+1,0);
	for (int i=0;i<M;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int b = q.front();
		q.pop();
		for (int nb : adj[b])
			if (parent[nb]==0) {
				parent[nb]=b;
				q.push(nb);
			}
	}
	if (parent[N]==0) cout<<"IMPOSSIBLE";
	else {
		vector<int> ans = {N};
		while (ans.back()!=1)
			ans.push_back(parent[ans.back()]);
		reverse(begin(ans),end(ans));
		cout<<ans.size()<<"\n";
		for (int t : ans) cout<<t<<" ";
	}
	return 0;
}