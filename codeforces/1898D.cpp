#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	int n; cin>>n;
	vector<ll> a(n), b(n);
	for (ll& i : a) cin>>i;
	for (ll& i : b) cin>>i;
	ll maxa = 0, minb = 1e9+1;
	ll diff = 0;
	for (int i=0;i<n;i++) {
		maxa = max(maxa, min(a[i],b[i]));
		minb = min(minb, max(b[i],a[i]));
		diff += abs(a[i] - b[i]);
	}
	cout << diff + max(0ll, 2*(maxa-minb)) << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}