#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while (T --> 0) {
		int n,m;cin>>n>>m;
		int grid[n][m], ans[n][m];
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				cin>>grid[i][j];
		if (n*m==1) cout << "-1\n";
		else if (n==1) {
			for (int i=0;i<m;i++)
				cout << grid[0][(i-1+m)%m] << " ";
			cout << '\n';
		} else {
			for (int i=0;i<n;i++) {
				for (int j=0;j<m;j++)
					cout << grid[(i-1+n)%n][j] << " ";
				cout << '\n';
			}

		}
	}
	return 0;
}