#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f first
#define s second


void solve() {
	int n, ans=0; cin>>n;
	stack<pii> s;
	for (int i=0;i<n;i++) {
		int a,b; cin>>a>>b;
		int mx = 0;
		while (!s.empty()) {
			if (s.top().s == b)
				a += s.top().f - mx;
			else if (s.top().f <= a)
				mx = max(mx, s.top().f);
			else break;
			s.pop();
		}
		s.push({a,b});
		ans = max(ans,a);
		cout << ans << " ";
	}
	cout << '\n';
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}