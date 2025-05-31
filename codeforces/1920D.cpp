#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n,q; cin>>n>>q;
	vector<array<int, 3>> mods;
	vector<int> stage;
	int len = 0, k = 0;
	bool skip = false;
	for (int i=0;i<n;i++) {
		int t, inp; cin>>t>>inp;
		if (skip) continue;
		if (t == 1) {
			mods.push_back({k, len++, inp});
		} else {
			stage.push_back(len);
			int mul = min(((int) 2e18+1)/len, 1 + inp);
			if (mul < 1 + inp) skip = 1;
			len *= mul;
			k++;
		}
	}
	stage.push_back(len);
	int s = 0;
	for (auto& p : mods) {
		s = max(s, p[0]);
		p[0] = stage[p[0]];
		// cout << p[0] << " " << p[1] << " " << p[2] << endl;
	}
	s++;
	for (int i=0;i<q;i++) {
		int a, p = s-1; cin>>a; a--;
		array<int, 3> key = {stage[p], a%stage[p], 0};
		auto it = upper_bound(mods.begin(), mods.end(), key);
		// cout << stage[p] << " " << (*it)[0] << " " << (*it)[1] << " " << (*it)[2] << endl;
		a %= (*it)[0];
		while (p > 0 && a < (*it)[1]) {
			p--;
			array<int, 3> key = {stage[p], a%stage[p], 0};
			it = upper_bound(mods.begin(), mods.end(), key);
			a %= (*it)[0];
		}
		// cout << "first valid rule: " << endl;
		// cout << a << " " << (*it)[0] << " " << (*it)[1] << " " << (*it)[2] << endl;
		while (a > (*it)[1]) {
			it++;
		}
		cout << (*it)[2] << ((i<q-1)?" ":"");
	}
	cout << endl;
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}