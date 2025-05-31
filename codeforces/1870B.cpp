#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,m; cin>>n>>m;
	int inp, xorr = 0;
	for (int i=0;i<n;i++) {
		cin>>inp; xorr ^= inp;
	}
	if (n & 1) {
		int mn = xorr;
		for (int i=0;i<m;i++) {
			cin>>inp;
			xorr |= inp;
		}
		cout << mn << " " << xorr << endl;
	} else {
		int mx = xorr;
		for (int i=0;i<m;i++) {
			cin>>inp;
			xorr ^=  xorr & inp;
		}
		cout << xorr << " " << mx << endl;

	}
	
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}