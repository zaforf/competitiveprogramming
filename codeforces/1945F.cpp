#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, inp; cin>>n;
	vector<int> p(n), a(n);
	multiset<int> all, in;
	for (int i=0;i<n;i++) {
		cin>>inp;
		all.insert(inp);
		a[i] = inp;
	}
	for (int i=0;i<n;i++) {
		cin>>inp;
		p[i] = inp-1;
	}
	long long mul = 1;
	long long best = 1;
	int amt = 1;
	for (int sz=0;sz<n;sz++) {
		bool rem = 0;
		if (sz) {
			auto it = in.find(a[p[sz-1]]);
			if (it != in.end()) {
				in.erase(it);
				rem = 1;
			}
			if (!rem) all.erase(all.find(a[p[sz-1]]));
		}
		// cout << sz << endl;
		if (all.empty()) break;
		in.insert(*all.rbegin());
		all.erase(--all.end());
		if (rem) {
			if (all.empty()) break;
			in.insert(*all.rbegin());
			all.erase(--all.end());
		}
		mul = *in.begin() * (sz+1ll);
		// cout << mul << " " << sz << endl;
		if (mul > best) {
			best = mul;
			amt = sz + 1;
		}
	}
	cout << best << " " << amt << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}