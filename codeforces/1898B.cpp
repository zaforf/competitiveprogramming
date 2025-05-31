#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& i : a) cin>>i;
	reverse(a.begin(),a.end());
	int mn = a[0];
	long long ops = 0;
	for (int i=1;i<n;i++) {
		if (a[i] <= mn) {
			mn = min(a[i], mn);
			continue;
		}
		int ceil = (a[i] + mn - 1) / mn;
		mn = a[i] / ceil;
		ops += ceil - 1;
	}
	cout << ops << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}