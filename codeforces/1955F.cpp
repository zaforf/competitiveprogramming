#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a,b,c,d; cin>>a>>b>>c>>d;
	int ans = 0;
	if ((a & 1) && (b & 1) && (c & 1)) ans++;
	ans += a/2;
	ans += b/2;
	ans += c/2;
	ans += d/2;
	cout << ans << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}