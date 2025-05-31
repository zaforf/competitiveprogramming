#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;

int binexp(int a, int b) {
	int ret=1;
	while (b) {
		if (b&1) {
			ret *= a;
			ret %= MOD;
		}
		a *= a;
		a %= MOD;
		b >>= 1;
	}
	return ret;
}

int32_t main() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& i : a) cin>>i;
	int ans = 0;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			int dist = a[j] - a[i];
			auto left_it = lower_bound(a.begin(), a.end(), a[i] - dist);
			int left_len = (a.begin() + i) - left_it;
			auto right_it = lower_bound(a.begin(), a.end(), a[j] + dist);
			int right_len = (right_it - 1) - (a.begin() + j);
			int iter = ((binexp(2, left_len) - 1) * (binexp(2, right_len) - 1) % MOD + MOD) % MOD;
			iter = iter * binexp(2, (n - (j - i + 1) - left_len - right_len)) % MOD;
			ans = (ans + iter) % MOD;
		}
	}
	ans = (ans + binexp(2, n) - n - 1 + MOD) % MOD;
	cout << ans << endl;
	return 0;
}