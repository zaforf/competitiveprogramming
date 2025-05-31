#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	int cntzero = 0;
	int firstzero = -1;
	int lastzero = -1;
	for (int i=0;i<n;i++) {
		cin >> a[i];
		if (a[i] == 0) {
			cntzero++;
			if (firstzero == -1)
				firstzero = i;
			lastzero = i;
		}
	}
	if (cntzero == 0) {
		cout << 1 << endl << 1 << " " << n << endl;
	} else {
		if (firstzero == 0 && lastzero == n-1) {
			cout << 3 << endl;
			cout << 3 << " " << n << endl;
			cout << 1 << " " << 2 << endl;
			cout << 1 << " " << 2 << endl;
		} else if (firstzero == lastzero) {
			if (firstzero == 0) {
				cout << 2 << endl;
				cout << 1 << " " << 2 << endl;
				cout << 1 << " " << n-1 << endl;
			} else if (firstzero == n-1) {
				cout << 2 << endl;
				cout << n-1 << " " << n << endl;
				cout << 1 << " " << n-1 << endl;
			} else {
				cout << 2 << endl;
				cout << 1 << " " << firstzero+1 << endl;
				cout << 1 << " " << n-firstzero << endl;
			}
		} else {
			cout << 2 << endl;
			cout << firstzero+1 << " " << lastzero+1 << endl;
			cout << 1 << " " << n-(lastzero - firstzero) << endl;
		}
	}

}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}