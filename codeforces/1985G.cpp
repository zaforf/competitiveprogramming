#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
#define int long long

int binexp(int a, int b) {
	int ret=1;
	while (b) {
		if (b&1) {
			ret *= a;
			ret %= MOD;
		}
		a *= a;
		a %= MOD;
		b >>= 1;
	}
	return ret;
}

void solve() {
	int l,r,k; cin>>l>>r>>k;
	int x = 1;
	while (x*k < 10) x++;
	cout << (binexp(x,r)-binexp(x,l)+MOD)%MOD << endl;
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}