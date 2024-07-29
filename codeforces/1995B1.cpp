#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int T; cin>>T;
	while (T-->0) {
		int n;
		ll m;cin>>n>>m;
		int a[n];
		for (int& i : a) cin>>i;
		sort(a,a+n);
		int l=0,r=0;
		ll ans=0,c=0;
		for (;l<n;l++) {
			if (a[l]>m) break;
			r = max(l,r);
			while (r<n && a[r]<a[l]+2 && c+a[r]<=m) c += a[r++];
			ans = max(ans,c);
			if (c) c -= a[l];
		}
		cout << ans << '\n';
	}
	return 0;
}