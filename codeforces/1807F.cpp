#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,m,si,sj,ei,ej; cin>>n>>m>>si>>sj>>ei>>ej;
	string dir_s; cin>>dir_s;
	array<int,2> d{0}, sd;
	if (dir_s[0]=='D') d[0]++;
	else d[0]--;
	if (dir_s[1]=='L') d[1]--;
	else d[1]++;
	sd = d;
	int ci = si, cj = sj;
	array<int,2> cd = d;
	int ans = 0;

	int inc = 0;
	if (cd[0] > 0 && ci == n)
		cd[0] *= -1, inc = 1;
	if (cd[0] < 0 && ci == 1)
		cd[0] *= -1, inc = 1;
	if (cd[1] < 0 && cj == 1)
		cd[1] *= -1, inc = 1;
	if (cd[1] > 0 && cj == m)
		cd[1] *= -1, inc = 1;
	sd = cd;
	ans += inc;
	while (!(ci == ei && cj == ej)) {
		// cout << ci << " " << cj << " " << cd[0] << " " << cd[1] << endl;
		inc = 0;
		ci += cd[0];
		cj += cd[1];
		if (cd[0] > 0 && ci == n)
			cd[0] *= -1, inc = 1;
		if (cd[0] < 0 && ci == 1)
			cd[0] *= -1, inc = 1;
		if (cd[1] < 0 && cj == 1)
			cd[1] *= -1, inc = 1;
		if (cd[1] > 0 && cj == m)
			cd[1] *= -1, inc = 1;
		ans += inc;
		if (ci==si && cj==sj && cd == sd) break;
	}
	if (ci == ei && cj == ej)
		cout << ans-inc << endl;
	else
		cout << -1 << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}