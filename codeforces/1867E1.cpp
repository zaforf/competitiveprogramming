#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,k; cin>>n>>k;
	int r = n % k;
	int ans = 0, inp;
	if (r) {
		int p = r / 2;
		cout << "? " << p+1 << endl;
		int r_half; cin>>r_half;
		cout << "? " << 1 << endl;
		int l_half; cin>>l_half;
		ans = l_half ^ r_half;
		// restore array
		cout << "? " << 1 << endl; cin>>inp;
		cout << "? " << p+1 << endl; cin>>inp;
	}
	for (int l = r; l < n; l += k) {
		cout << "? " << l+1 << endl;
		int inp; cin>>inp;
		ans ^= inp;
	}
	cout << "! " << ans << endl;
	
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}