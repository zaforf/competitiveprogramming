#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;cin>>n>>k;
	double prob[n][k+1];
	for (int i=0;i<n;i++) for (int j=0;j<k+1;j++) prob[i][j]=0;
	for (int i=1;i<k+1;i++)
		prob[0][i]=1.0/k;
	for (int s=1;s<n;s++)
		for (int i=1;i<k+1;i++)
			for (int j=1;j<k+1;j++)
				prob[s][max(i,j)] += prob[s-1][i]*1.0/k;
	double ans = 0;
	for (int i=1;i<k+1;i++)
		ans += i*prob[n-1][i];
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}