#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,q; cin>>n>>q;
	vector<int> prefix(n,0);
	for (int i=0;i<n;i++) {
		int inp; cin>>inp;
		prefix[inp]++;
	}
	for (int i=1;i<n;i++) prefix[i] += prefix[i-1];
	for (int i=0;i<q;i++) {
		int t; cin>>t;
		int ans = 0;
		if (t>n-1-t && (t>=n-1 || prefix[t] - prefix[n-1-t] > 0)) {
			cout << "-1\n";
			continue;
		}
		ans += prefix[t];
		ans += prefix[n-1] - prefix[n-1-t];
		cout << ans << endl;
	}
	
}

int main() {
	// int T;cin>>T;
	// while (T --> 0) {
		solve();
	// }
	return 0;
}