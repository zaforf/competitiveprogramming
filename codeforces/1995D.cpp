#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,c,k;cin>>n>>c>>k;
	string s; cin>>s;
	vector<vector<int>> pre(c,vector<int>(n+1));
	for (int l=0;l<c;l++)
		for (int i=0;i<n;i++)
			pre[l][i+1] = pre[l][i]+(s[i]==l+'A');

	vector<bool> bad(1<<c);
	for (int i=0;i<=n-k;i++) {
		int lets = 0;
		for (int l=0;l<c;l++)
			if (pre[l][i+k]-pre[l][i]) lets |= (1<<l);
		bad[(1<<c)-1 ^ lets] = true;
		// not containing these letters is bad
	}
	bad[(1<<c)-1 ^ (1<<(s[n-1]-'A'))] = true;
	// not containing the last letter is bad

	int best = c;
	for (int i=(1<<c)-1;i>=0;i--) {
		for (int b=0;b<c;b++)
			bad[i] = bad[i] | bad[i|(1<<b)];
		if (!bad[i] && __builtin_popcount(i)<best) best = __builtin_popcount(i);
	}
	// any subset of bad combination is bad
	cout << best << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}