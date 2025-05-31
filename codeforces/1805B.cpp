#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	string s; cin>>s;
	int l = 0;
	for (int i=0;i<n;i++) {
		if (s[i] <= s[l])
			l = i;
	}
	cout << s[l];
	for (int i=0;i<n;i++)
		if (i==l) continue;
		else cout << s[i];
	cout << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}