#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> ans(n,1);
	int a,b;cin>>b>>a;a--;b--;
	int c = -1;
	for (int i=b+1;i<n;i++) {
		ans[i] = c;
		c *= -1;
	}
	c = -1;
	for (int i=a-1;i>=0;i--) {
		ans[i] = c;
		c *= -1;
	}
	for (const int& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}