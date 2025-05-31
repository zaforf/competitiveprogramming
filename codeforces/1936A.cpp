#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	int mx = 0; char res;
	for (int i=1;i<n;i++) {
		cout << "? " << mx << " " << mx << " " << i << " " << i << endl;
		cin >> res;
		if (res == '<') mx = i;
	}
	vector<int> mx_ors(1);
	for (int i=1;i<n;i++) {
		cout << "? " << mx << " " << mx_ors.front() << " " << mx << " " << i << endl;
		cin >> res;
		if (res == '<') {
			mx_ors.clear();
			mx_ors.push_back(i);
		} else if (res == '=') {
			mx_ors.push_back(i);
		}
	}
	int mn = mx_ors.front(), sz = mx_ors.size();
	for (int i=1;i<sz;i++) {
		cout << "? " << mn << " " << mn << " " << mx_ors[i] << " " << mx_ors[i] << endl;
		cin >> res;
		if (res == '>') mn = mx_ors[i];
	}
	cout << "! " << mn << " " << mx << endl;
	// 4 1 2 3 0
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}