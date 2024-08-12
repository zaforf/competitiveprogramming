#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n; cin>>n>>n;
	vector<int> a(n+2), pre(n+2), ord(n), ans(n+2,0);
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		ord[i-1]=i;
		pre[i] = pre[i-1] + a[i];
	}
	sort(ord.begin(),ord.end(),[&](int x, int y) {
		return a[x]>a[y];
	});
	set<int> s{0,n+1};
	for (int i : ord) {
		int r = *s.lower_bound(i);
		int l = *prev(s.lower_bound(i));
		int range = pre[r-1]-pre[l];

		if (i==ord[0]) ans[i] = true;
		if (range>=a[l]) ans[i] |= ans[l];
		if (range>=a[r]) ans[i] |= ans[r];
		s.insert(i);
	}
	cout << accumulate(ans.begin(),ans.end(),0ll) << '\n';
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}