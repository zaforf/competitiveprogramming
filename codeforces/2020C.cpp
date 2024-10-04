#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int b,c,d; cin>>b>>c>>d;
	int a = 0;
	for (int i = 0; i < 64; i++) {
		int x = b&(1ll<<i);
		int y = c&(1ll<<i);
		int z = d&(1ll<<i);
		// cout << (x>0) << (y>0) << (z>0) << endl;
		if (x&y) {
			a |= (z ? 0 : 1ll<<i);
			continue;
		}
		if ((!x) && (!y)) {
			a |= (z ? 1ll<<i : 0);
			continue;
		}
		if (((x && (!y)) || (y && (!x))) && (z==y)) {
			cout << -1 << endl;
			return;
		} else {
			a |= 1ll<<i;
		}
	}
	cout << (a <= pow(2ll,61) && a > 0 ? a : 0) << endl;
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}