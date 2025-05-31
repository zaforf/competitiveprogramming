#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& i : a) cin>>i;
	multiset<int> fwd;
	multiset<int> bwd;
	for (int i=n-1;i>0;i--)
		fwd.insert(a[i]-i);
	int ans = 0;
	bwd.insert(a[0]);
	for (int i=1;i<n-1;i++) {
		fwd.erase(fwd.find(a[i]-i));
		ans = max(ans, *bwd.rbegin() + a[i] + *fwd.rbegin());
		bwd.insert(a[i] + i);
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