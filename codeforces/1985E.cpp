#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int x,y,z,k; cin>>x>>y>>z>>k;
	int ans = 0;
	for (int i=1;i<=x;i++)
		for (int j=1;j<=y;j++) {
			if (k%(i*j) || k/(i*j)>z) continue;
			int p = k/(i*j);
			ans = max(ans,(x-i+1)*(y-j+1)*(z-p+1));
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