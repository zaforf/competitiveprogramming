#include <bits/stdc++.h>
using namespace std;
#define int long long

int log3(int a) {
	return log2(a)/log2(3);
}

void solve() {
	int l,r;cin>>l>>r;
	int ans = 0, m = l;
	while (l) {
		l /= 3;
		ans += 2;
	}
	int curr = log3(m+1);
	int last = pow(3,curr+1)-1;
	for (int i=m+1;i<=r;) {
		ans += (min(r,last)-i+1)*curr;
		i = last + 1;
		curr++;
		last = pow(3,curr+1)-1;
	}
	cout << ans+r-m << '\n';
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}