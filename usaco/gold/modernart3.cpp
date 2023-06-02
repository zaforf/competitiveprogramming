#include <bits/stdc++.h>
using namespace std;
const int MAXN=300;
int A[MAXN],dp[MAXN][MAXN];


int main() {
	int N;cin>>N;
	for (int i=0;i<N;i++) cin>>A[i];
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			dp[i][j]= i==j ? 1 : MAXN;

	for (int s=0;s<N;s++)
		for (int i=0;i+s<N;i++)
			for (int j=i;j<i+s;j++) {
				int k=i+s;
				if (A[i]==A[k]) dp[i][k]=min(dp[i][k],dp[i][j]+dp[j+1][k]-1);
				dp[i][k]=min(dp[i][k],dp[i][j]+dp[j+1][k]);
			}
	cout<<dp[0][N-1];
	return 0;
}