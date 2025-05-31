#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, k; cin>>n>>k;
	if (k > n || (k > (n + 1)/2 && k < n)) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	cout << 2 << endl;
	cout << n - k + 1 << " " << 1 << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}