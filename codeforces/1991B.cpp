#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n; n--;
	vector<int> a(n), b(n+1);
	for (int i=0;i<n;i++) {
		cin>>a[i];
		b[i]|=a[i];
		b[i+1]|=a[i];
	}
	for (int i=0;i<n;i++) {
		if ((b[i]&b[i+1])!=a[i]) {
			cout << "-1\n";
			return;
		}
	}
	for (int x : b) cout << x << " ";
	cout << "\n";
}

int main() {
	int T; cin>>T;
	while (T --> 0) solve();
	return 0;
}