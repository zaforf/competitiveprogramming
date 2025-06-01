#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& x : a) cin>>x;
	reverse(a.begin(), a.end());
	int mn = 1e9, mn_ind = 0;
	long long ans = 0;
	for (int i=0;i<n;i++) {
		ans += min(mn, a[i]);
		if (mn <= a[i]) { // swap
			mn -= i - mn_ind;
		} else {
			mn = min(mn+1, a[i]);
		}
		mn++;
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