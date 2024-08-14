#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n; cin>>n;
	int a[n]; for (int & i : a) cin>>i;
	string s; cin>>s;
	vector<int> pre(n+1);
	for (int i=1;i<=n;i++)
		pre[i] = pre[i-1]+a[i-1];
	vector<int> Ls, Rs;
	for (int i=0;i<n;i++) {
		if (s[i]=='L') Ls.push_back(i);
		else Rs.push_back(i);
	}
	reverse(Rs.begin(),Rs.end());
	int ans = 0;
	for (int i=0;i<Ls.size() && i<Rs.size();i++) {
		if (Ls[i]>Rs[i]) break;
		ans += pre[Rs[i]+1] - pre[Ls[i]];
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