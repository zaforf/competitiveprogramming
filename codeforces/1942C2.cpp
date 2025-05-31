#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,x,oy,y; cin>>n>>x>>oy; y = oy;
	vector<int> a(x);
	for (int& i : a) cin>>i;
	sort(a.begin(),a.end());
	int ans = x - 2;
	int even_gap = 0, tri_odd_gaps = 0;
	for (int i=1;i<x;i++) {
		int gap = a[i] - a[i-1];
		if (!(gap & 1) && gap/2 - 1 <= y) {
			y -= gap/2 - 1;
			ans += gap/2;
		} else if (!(gap & 1)) {
			even_gap = gap;
		} else {
			tri_odd_gaps += (gap - 1) / 2;
		}
	}
	int gap = a[0] + n - a[x-1];
	if (!(gap & 1) && gap/2 - 1 <= y) {
		y -= gap/2 - 1;
		ans += gap/2;
	} else if (!(gap & 1)) {
		even_gap = gap;
	} else {
		tri_odd_gaps += (gap - 1) / 2;
	}
	if (even_gap) {
		ans += y;
		y = 0;
	}
	tri_odd_gaps = min(tri_odd_gaps, y);
	y -= tri_odd_gaps;
	ans += tri_odd_gaps;
	ans += oy - y;
	cout << ans << endl;
	
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}