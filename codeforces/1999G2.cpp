#include <bits/stdc++.h>
using namespace std;

void solve() {
	int l = 2, r = 999;
	while (l<r) {
		int m1 = l+(r-l)/3;
		int m2 = r-(r-l)/3;
		if (m2<m1) swap(m1,m2);
		cout << "? " << m1 << " " << m2 << endl;
		int res; cin>>res;
		if (res==(m2+1)*m1) {
			r = m2; l = m1+1;
		} else if (res==(m2+1)*(m1+1)) {
			r = m1;
		} else l = m2+1;
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