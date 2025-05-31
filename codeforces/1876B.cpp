#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
#define int long long

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

signed main() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	vector<int> step(n);
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			step[i-1] = max(step[i-1], a[j-1]);
	long long ans = 0;
	sort(step.begin(),step.end());
	for (int i=0;i<n;i++) {
		ans = (ans + (step[i] * binexp(2,i)) % MOD) % MOD;
	}
	cout << ans;
	return 0;
}