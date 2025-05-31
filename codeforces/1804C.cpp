#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,x,p; cin>>n>>x>>p;
	for (int i=1;i<=min(2*n,p);i++) {
		if ((n - x) % n == (i*(i+1ll)/2) % n) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}