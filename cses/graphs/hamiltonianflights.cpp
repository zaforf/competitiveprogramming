#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> reach(21);
int N,E;
long long dp[1<<20][21];

int main() {
	cin>>N>>E;
	for (int i=0;i<E;i++) {
		int a,b;cin>>a>>b;
		reach[b].push_back(a);
	}
	dp[1][1]=1;
	for (int s=2;s<(1<<20);s++) {
		if ((s & (1 << 0)) == 0) continue;
		if (s&(1<<(N-1)) && s!=((1<<N)-1)) continue;
		for (int k=1;k<=N;k++) {
			if (!(s&(1<<(k-1)))) continue;
			for (int d : reach[k]) {
				if (s&(1<<(d-1))) {
					dp[s][k]+=dp[s-(1<<(k-1))][d];
					dp[s][k]%=1000000007;
				}
			}
		}
	}
	cout<<dp[(1<<N)-1][N];
	return 0;
}