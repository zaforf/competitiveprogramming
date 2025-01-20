#include <bits/stdc++.h>
using namespace std;

const int max_n = 100000;
int a[max_n];

int pass(int n, int x) {
	int c = 0, k = 0;
	for (int i=0;i<n;i++) {
		c ^= a[i];
		if ((c | x) == x) {
			k++;
			c = 0;
		} else if (i == n-1)
			return -1;
	}
	return k;
}

void solve() {
	int n, x; cin>>n>>x;
	for (int i=0;i<n;i++)
		cin>>a[i];
	int ans = pass(n,x);
	for (int b=29;b>=0;b--) {
		if (x & (1 << b)) {
			int y = x ^ (1 << b);
			y |= (1 << b) - 1;
			ans = max(ans, pass(n,y));
		}
	}
	cout << ans << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}