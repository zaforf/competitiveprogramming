#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n; cin>>n;
	int a[n]; for (int& i : a) cin>>i;
	int odd = 0, maxodd = 0;
	for (int i : a) {
		if (i%2) maxodd = max(maxodd,i);
		if (i%2) odd++;
	}
	if (odd==0 || odd==n) {
		cout << "0\n";
		return;
	}
	sort(a,a+n);
	int extra = 0;
	for (int i : a) if (i%2==0) {
		if (maxodd>i) maxodd += i;
		else extra++;
	}
	cout << n-odd+(extra>0) << '\n';
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}