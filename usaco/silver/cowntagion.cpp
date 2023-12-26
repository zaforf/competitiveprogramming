#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin>>N;
	vector<int> adj(N+1);
	adj[1]=1;
	for (int i=0;i<N-1;i++) {
		int a,b;cin>>a>>b;
		adj[a]++;adj[b]++;
	}
	int ans=0;
	// for (auto a : adj)
	// 	cout<<a<<" ";
	// cout<<endl;
	for (int i=1;i<=N;i++) {
		if (adj[i]<2) continue;
		ans += (int) (log2(adj[i])+(__builtin_popcount(adj[i])==1?0:1));
		ans += adj[i]-1;
		// cout<<i<<" processed, ans is "<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}