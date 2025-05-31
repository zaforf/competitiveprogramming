#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& i : a) cin>>i;
	int must = 0, can = 0;
	int goal = (n-1)/2;
	for (int i=1;i<n;i++) {
		if (abs(a[i]) < a[0]) must++;
		else if (-abs(a[i]) < a[0]) can++;
	}
	if (must <= goal && goal <= must+can) {
		cout << "YES" << endl;
		return;
	}
	must = 0, can = 0;
	for (int i=1;i<n;i++) {
		if (abs(a[i]) < -a[0]) must++;
		else if (-abs(a[i]) < -a[0]) can++;
	}
	if (must <= goal && goal <= must+can) {
		cout << "YES" << endl;
		return;
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