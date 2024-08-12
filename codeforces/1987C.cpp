#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	int a[n]; for (int& i : a) cin>>i;
	int time = a[n-1];
	for (int i=n-2;i>=0;i--)
		time = max(time+1,a[i]);
	cout << time << '\n';
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}