#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,m,sz; cin>>n>>m;
	vector<vector<int>> lists(n);
	int mx = 0;
	for (int i=0;i<n;i++) {
		cin >> sz;
		lists[i].resize(sz);
		for (int& j : lists[i]) cin >> j;
		set<int> in(lists[i].begin(), lists[i].end());
		for (int i=0;i<=sz;i++)
			if (!in.contains(i)) {
				in.insert(i);
				break;
			}
		for (int i=0;i<=sz+1;i++) {
			if (!in.contains(i)) {
				mx = max(mx, i);
				break;
			}
		}
	}
	long long ans = 1ll*mx*(min(m,mx)+1);
	if (m > mx)
		ans += m*(m+1ll)/2 - mx*(mx+1ll)/2;
	cout << ans << endl;

}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}