#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, inp; cin>>n;
	cout << "+ " << n + 1 << endl; cin >> inp;
	cout << "+ " << n + 2 << endl; cin >> inp;
	int mx_dist = 0, mx_node = -1;
	for (int i = 2; i <= n; i++) {
		cout << "? 1 " << i << endl;
		cin >> inp;
		if (inp > mx_dist) {
			mx_dist = inp;
			mx_node = i;
		}
	}
	vector<int> conv(n);
	int c = 1;
	for (int i=0;i<n;i++) {
		conv[i] = c;
		c = n + 1 - c;
		if (i & 1) c++;
	}
	vector<int> ans(n);
	ans[0] = mx_node;
	for (int i = 1; i <= n; i++) {
		if (i == mx_node) continue;
		cout << "? " << mx_node << " " << i << endl;
		cin >> inp;
		ans[inp] = i;
	}
	cout << "! ";
	vector<int> print(n);
	for (int i=0;i<n;i++) {
		print[ans[i]-1] = conv[i];
	}
	for (int i : print) cout << i << " ";
	for (int i=0;i<n;i++) {
		print[ans[i]-1] = conv[n-i-1];
	}
	for (int i : print) cout << i << " ";
	cout << endl;
	cin >> inp;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}