#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
	int n, k; cin >> n >> k;
	vector<int> a(n), b(n);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;
	long long ans = 0;
	int less = 0, eq = 0;
	bool first_since_eq = 0;
	int last_more = -1;
	int last_less = -1;
	for (int i = 0; i < n; i++) {
				// go up to k
		if (i > last_more + 1)
			ans = (ans + ((last_less - last_more) * (k - a[i]) % MOD) * (n - i) % MOD) % MOD;
		if (a[i] < b[i])  {
			ans = (ans + ((i - last_less) * (b[i] - a[i]) % MOD) * (n - i) % MOD) % MOD;
		}
		if (a[i] < b[i]) {
			last_less = i;
			less++;
		} else if (a[i] == b[i]) {
			eq++;
			first_since_eq = 1;
		} else {
			eq = 0;
			first_since_eq = 0;
			last_more = i;
		}
	}
	cout << ans;
	return 0;
}