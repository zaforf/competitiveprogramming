#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int n; cin >> n;
	int ans = 0, open = 0;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	for (int i=0;i<n;i++) {
		if (a[i] > (i ? a[i-1] : 0)) {
			ans += a[i] - open + 1;
			open = a[i];
		} else open = a[i];
	}
	cout << ans + 1 << endl;
	return 0;
}