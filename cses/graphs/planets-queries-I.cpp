#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int k[MAXN][30];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin >> k[i][0];
	for (int i=1;i<30;i++) {
		for (int j=0;j<=n;j++) {
			k[j][i] = k[k[j][i-1]][i-1];
		}
	}
	for (int i=0;i<q;i++) {
		int x,d;cin>>x>>d;
		for (int j=0;j<30;j++) {
			if (d & (1<<j)) x = k[x][j];
		}
		cout << x << endl;
	}
	return 0;
}