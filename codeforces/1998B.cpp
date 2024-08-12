#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	int a[n]; for (int& i : a) cin>>i;
	for (int i=1;i<n;i++) cout << a[i] << " ";
	cout << a[0] << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}