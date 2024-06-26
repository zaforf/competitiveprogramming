#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		int n,m,k;cin>>n>>m>>k;
		int grid[n][m]; string snowy[n];
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				cin>>grid[i][j];
		for (int i=0;i<n;i++)
			cin>>snowy[i];
		int diff=0,gcf=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				diff += grid[i][j]*(snowy[i][j]=='1'?1:-1);
		int pfix[n+1][m+1] = {0};
		for (int i=0;i<n+1;i++)
			for (int j=0;j<m+1;j++) {
				if (i==0 || j==0) {
					pfix[i][j]=0;
					continue;
				}
				pfix[i][j]=pfix[i][j-1]+pfix[i-1][j]-pfix[i-1][j-1]+(snowy[i-1][j-1]=='1'?1:-1);
			}
		for (int i=0;i<n-k+1;i++)
			for (int j=0;j<m-k+1;j++)
				gcf = gcd(gcf,pfix[i+k][j+k]-pfix[i+k][j]-pfix[i][j+k]+pfix[i][j]);
		if (gcf==0) cout << (diff?"NO":"YES") << endl;
		else cout << ((diff%gcf==0)?"YES":"NO") << endl;
	}
	return 0;
}