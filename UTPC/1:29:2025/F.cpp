#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q; cin >> n >> q;
	multiset<int> in;
	vector<int> a(n);
	for (int i=0;i<n;i++) {
		cin >> a[i];
		in.insert(a[i]);
	}
	for (int i=0;i<q;i++) {
		int t; cin >> t;
		if (t == 1) {
			int inp; cin >> inp;
			int x = a[inp-1];
			cout << *in.rbegin() - x << endl;
		} else {
			int x, v; cin >> x >> v;
			in.erase(in.find(a[x-1]));
			a[x-1] = v;
			in.insert(v);
		}
	}

	return 0;
}