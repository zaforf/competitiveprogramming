#include <bits/stdc++.h>
using namespace std;
#define double long double
const double eps = 1e-9; 

void solve() {
	int n; cin>>n;
	double a[n];
	for (int i=0;i<n;i++) {
		cin >> a[i];
		a[i] = log(log(a[i]));
	}
	long long ans = 0, cnt;
	for (int i=1;i<n;i++) {
		if (a[i]<a[i-1]) {
			if (a[i]==log(0)) {
				cout << "-1\n";
				return;
			} else {
				cnt = 1 + (a[i-1]-a[i]-eps)/log(2);
				ans += cnt;
				a[i] += cnt*log(2);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	int T; cin>>T;
	while (T --> 0) solve();
	return 0;
}