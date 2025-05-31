#include <bits/stdc++.h>
using namespace std;

int check(string s, int m) {
	string snew = s.substr(0, m) + '$' + s;
	int len = snew.size();
	vector<int> pi(len);
	for (int i = 1; i < len; i++) {
		int j = pi[i-1];
		while (j > 0 && snew[i] != snew[j])
			j = pi[j-1];
		if (snew[i] == snew[j])
			j++;
		pi[i] = j;
	}
	int i = m;
	int res = 0;
	while (i < len) {
		if (pi[i] == m) {
			res++;
			i += m;
		} else
			i++;
	}
	return res;
}

void solve() {
	int n,m; cin>>n>>m>>m;
	string s; cin>>s;
	int len = s.size();
	int l = 0, r = len;
	while (l < r) {
		int mid = (l+r+1)/2;
		if (check(s, mid) < m)
			r = mid - 1;
		else
			l = mid;
	}
	cout << l << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}