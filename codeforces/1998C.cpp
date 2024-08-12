#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f first
#define s second

void solve() {
	int n,k; cin>>n>>k;
	vector<pii> a(n);
	for (pii& p : a) cin>>p.f;
	for (pii& p : a) cin>>p.s;
	int inc_max=0,m;
	sort(a.begin(),a.end());

	// apply all operations to max
	for (int i=0;i<n;i++) if (a[i].s) {
		if (i<n/2) m = a[n/2].f;
		else m = a[n/2-1].f;
		inc_max = max(inc_max,m+a[i].f+k);
	}

	// apply all operations to median
	int lo=0,hi=1e9+1,mid;
	while (lo<hi) {
		mid = (lo+hi+1)/2;

		int z = 0;
		vector<int> change;
		for (int i=0;i<n-1;i++) {
			if (a[i].f>=mid) z++;
			else if (a[i].s) change.push_back(mid-a[i].f);
		}
		reverse(change.begin(),change.end());
		int kk = k;
		for (int i=0;i<change.size();i++) {
			if (change[i]<=kk) {
				z++;
				kk-=change[i];
			} else break;
		}

		if (z>=(n+1)/2) lo = mid;
		else hi = mid-1;
	}
	cout << max(inc_max,lo+a.back().f) << '\n';
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}