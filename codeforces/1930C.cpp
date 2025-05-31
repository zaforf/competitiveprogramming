#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& i : a) cin>>i;
	set<int> used, not_used;
	vector<int> ans;
	for (int i=0;i<n;i++) {
		int hi=a[i]+i+1;
		if (!used.contains(hi))
			not_used.insert(hi);
		int best = *(--not_used.upper_bound(hi));
		not_used.erase(best);
		ans.push_back(best);
		used.insert(best);
		if (!used.contains(best-1))
			not_used.insert(best-1);
	}
	sort(ans.begin(),ans.end(),greater<>());
	for (int x : ans) cout << x << " ";
	cout << endl;
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}