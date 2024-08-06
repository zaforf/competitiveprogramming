#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
#define int long long

void solve() {
	int h,n; cin>>h>>n;
	vector<int> dmg(n), cool(n);
	priority_queue<pii,vector<pii>,greater<pii>> q;
	for (int& i : dmg) {
		cin>>i;
		h -= i;
	}
	for (int& i : cool) cin>>i;
	for (int i=0;i<n;i++) q.push({1+cool[i],i});
	int ans = 1;
	while (h>0) {
		auto [time,i] = q.top(); q.pop();
		ans = max(ans,time);
		h -= dmg[i];
		q.push({ans+cool[i],i});
	}
	cout << ans << '\n';
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}