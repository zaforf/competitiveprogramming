#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> dp(1<<20,{0,0}); // height, load

int main() {
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	int N,H;cin>>N>>H;
	vector<vector<int>> cows(N,vector<int>(3));
	for (int i=0;i<N;i++) {
		cin>>cows[i][0]>>cows[i][1]>>cows[i][2]; // height, weight, strength
		dp[(1<<i)]={cows[i][0],cows[i][2]};
	}
	for (int s=1;s<=(1<<N);s++) {
		for (int c=0;c<N;c++) {
			if (!(s&(1<<c)) || cows[c][1]>dp[s^(1<<c)].second) continue;
			int height = dp[s^(1<<c)].first+cows[c][0];
			dp[s]={height,max(dp[s].second,min(dp[s^(1<<c)].second-cows[c][1],cows[c][2]))};
		}
	}
	int ans=0;bool found=false;
	for (int s=1;s<=(1<<N);s++)
		if (dp[s].first>=H) {
			ans = max(ans,dp[s].second);found=true;
		}
	if (found)
		cout<<ans;
	else
		cout<<"Mark is too tall";
	return 0;
}