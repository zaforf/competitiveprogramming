#include <bits/stdc++.h>
using namespace std;

void solve() {
	int xc,yc,k; cin>>xc>>yc>>k;
	if (k&1) {
		for (int i=0;i<k;i++)
			cout << xc-k/2+i << " " << yc << '\n';
	} else {
		for (int i=0;i<k+1;i++) {
			if (xc-k/2+i == xc) continue;
			cout << xc-k/2+i << " " << yc << '\n';
		}
	}
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}