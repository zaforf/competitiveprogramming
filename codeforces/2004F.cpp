#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n; cin>>n;
	vector<int> a(n),p(n+1); for (int& i : a) cin>>i;
	for (int i=1;i<n+1;i++) p[i] = p[i-1]+a[i-1];
	ll ans = 0;
	map<ll,ll> c;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n+1;j++) {
			int s = p[j]-p[i];
			ans += j-i-1;
			ans -= c[s];
			c[s]++;
		}
	cout << ans << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}