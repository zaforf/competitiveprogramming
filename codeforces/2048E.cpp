#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,m; cin>>n>>m;
	if (m >= 2*n) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	vector<int> strip(2*n);
	for (int i=0;i<2*n;i++) {
		strip[i] = i/2+1;
	}
	for (int i=0;i<2*n;i++) {
		for (int j=i, k=0; k<m; j=(j+1)%(2*n), k++) {
			cout << strip[j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}