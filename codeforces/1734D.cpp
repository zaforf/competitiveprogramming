#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n,k; cin>>n>>k;
	auto cmp = [](array<int,3> a, array<int,3> b) {
		return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] > b[0]);
	};
	queue<array<int,2>> left, right;
	vector<int> a(n+2, 1e16);
	for (int i=1;i<=n;i++) cin >> a[i];
	int c = 0, mn = 0;
	for (int i=k+1;i<n+2;i++) {
		c += a[i];
		mn = max(mn, -c);
		if (c > 0) {
			right.push({mn, c});
			c = 0, mn = 0;
		}
	}
	c = 0, mn = 0;
	for (int i=k-1;i>=0;i--) {
		c += a[i];
		mn = max(mn, -c);
		if (c > 0) {
			left.push({mn, c});
			c = 0, mn = 0;
		}
	}
	int sum = a[k];
	while (left.size() || right.size()) {
		bool del = false;
		while (left.size() && sum >= left.front()[0]) {
			sum += left.front()[1];
			left.pop();
			del = true;
		}
		while (right.size() && sum >= right.front()[0]) {
			sum += right.front()[1];
			right.pop();
			del = true;
		}
		if (sum > 1e15) {
			cout << "YES" << endl;
			return;
		}
		if (!del) break;
	}
	cout << "NO" << endl;
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}