#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int x; cin>>x; x--;
	int b = 63-__builtin_clzll(x);
	if (x+1 == 1ll<<b) {
		cout << b+1 << endl;
		for (int i=0;i<=b;i++)
			cout << i << " ";
		cout << endl;
		return;
	}
	vector<int> ans;
	int g = x;
	for (int i=0;i<b;i++) {
		ans.push_back(i);
		g -= (1ll << i);
	}
	for (int i=b;i>=0;i--) {
		if (g & (1ll<<i)) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int v : ans) cout << v << " ";
	cout << endl;
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}