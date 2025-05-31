#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	int c = 0;
	for (int& i : a) {
		cin >> i;
		c += i;
	}
	if (c == n) {
		cout << "YES" << endl;
		return;
	}
	for (int i=0;i<n-1;i++) {
		if (!a[i] && !a[i+1]) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;

}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}