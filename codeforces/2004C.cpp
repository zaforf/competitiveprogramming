#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,k; cin>>n>>k;
	vector<int> a(n); for (int& i : a) cin>>i;
	sort(a.begin(),a.end());
	long long diff = 0;
	for (int i=n-2;i>=0;i-=2) {
		if (a[i+1]-a[i]>0) {
			int c = min(a[i+1]-a[i],k);
			a[i] += c;
			k -= c;
		}
		diff += a[i+1]-a[i];
	}
	if (n&1) diff += a[0];
	cout << diff << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}