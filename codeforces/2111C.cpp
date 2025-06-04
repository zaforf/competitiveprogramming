#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	int l = 0;
	long long ans = 100000000000000000;
	for (int r=0;r<n;r++) {
		if (a[l] != a[r]) l = r;
		ans = min(ans, l*1ll*a[r] + (n-r-1ll)*a[r]);
	}
	cout << ans << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}