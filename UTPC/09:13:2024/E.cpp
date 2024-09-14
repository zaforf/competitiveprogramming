#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f first
#define s second

void solve() {
	int n,d,x; cin>>n>>d>>x;
	vector<pii> a(n);
	for (int i=0;i<n;i++)
		cin>>a[i].s;
	for (int i=0;i<n;i++)
		cin>>a[i].f;
	sort(a.begin(),a.end(),greater<pii>());
	int total = d*x, ans = 0;
	for (int i=0;i<n && total>0;i++) {
		int c = min(min(a[i].s,d),total);
		ans += c*a[i].f;
		total -= c;
	}
	cout << ans << endl;
	
}

int32_t main() {
	// int T;cin>>T;
	// while (T --> 0) {
		solve();
	// }
	return 0;
}