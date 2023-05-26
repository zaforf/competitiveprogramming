#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,K; cin>>N>>K;
	vector<pair<int,int>> vals(N);
	for (int i=0;i<N;i++) cin>>vals[i].first;
	for (int i=0;i<N;i++) cin>>vals[i].second;
	vector<vector<int>> dp(N+1,vector<int>(K+1)); // dp[consider first n][cost] = # pages
	if (vals[0].first<=K) dp[1][vals[0].first]=vals[0].second;
	for (int i=1;i<N+1;i++)
		for (int j=0;j<K+1;j++) {
			dp[i][j]=dp[i-1][j];
			// dp[i][j]=max(dp[i][j],dp[i][j-1]);
			if (j-vals[i-1].first>=0)
				dp[i][j]=max(dp[i][j],dp[i-1][j-vals[i-1].first]+vals[i-1].second);
		}
	// for (int i=0;i<N+1;i++) {
	// 	for (int j=0;j<K+1;j++) 
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<"\n";
	// }
	cout<<dp[N][K];
	return 0;
}