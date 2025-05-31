#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> ans;
	if (n & 1) {
		if ((n - 1) % 4 == 0)
			ans.push_back(0);
		else
			ans.push_back(1 << 30);
	}
	for (int i=0;i<n - (n & 1);i++) {
		if (i & 1)
			ans.push_back(i | (1 << 30));
		else
			ans.push_back(i+1);
	}
	if (n % 4 == 2) {
		ans[n-1] |= 1<<29;
		ans[n-1] ^= 1<<30;
		ans[n-3] |= 1<<29;
	}
	for (int x : ans)
		cout << x << " ";
	cout << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}