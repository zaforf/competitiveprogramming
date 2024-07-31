#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int lift[MAXN][19];

int main() {
	int n,q; cin>>n>>q;
	lift[1][0] = -1;
	for (int i=2;i<=n;i++) cin>>lift[i][0];
	for (int k=1;k<19;k++) {
		for (int i=1;i<=n;i++) {
			int par = lift[i][k-1];
			if (par == -1) lift[i][k] = -1;
			else lift[i][k] = lift[par][k-1];
		}
	}
	for (int i=0;i<q;i++) {
		int x, d, k=0; cin>>x>>d;
		while (d) {
			if (x == -1) break;
			if (d&1) x = lift[x][k];
			d >>= 1;
			k++;
		}
		cout << x << '\n';
	}
	return 0;
}