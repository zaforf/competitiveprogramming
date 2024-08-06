#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s,t;cin>>s>>t;
	vector<int> cnt(26);
	int r = 0;
	char last = t[0];
	for (int i=0;i<s.size() && r<t.size();i++) {
		if (s[i]=='?') {
			s[i] = last;
		} if (s[i]==t[r]) {
			if (r+1<t.size()) last = t[r+1];
			r++;
		}
	}
	if (r==t.size()) {
		for (int i=0;i<s.size();i++) if (s[i]=='?') s[i] = last;
		cout << "YES\n";
		cout << s << '\n';
	} else {
		cout << "NO\n";
	}
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}