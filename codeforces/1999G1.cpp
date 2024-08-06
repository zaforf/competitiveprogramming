#include <bits/stdc++.h>
using namespace std;

void solve() {
	int l = 2, r = 999;
	while (l<r) {
		int mid = (l+r)/2;
		cout << "? " << mid << " " << mid << endl;
		int res; cin>>res;
		if (res>mid*mid) r = mid;
		else l = mid+1;
	}
	cout << "! " << l << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}