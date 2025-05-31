#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	unordered_map<int,int> xs;
	unordered_map<int,int> ys;
	for (int i=0;i<n;i++) {
		int a,b; cin>>a>>b;
		xs[a]++;
		ys[a+b]++;
	}
	int fx = 0;
	for (auto const& [key, cnt] : xs)
		if (cnt & 1) {
			fx = key;
			break;
		}
	cout << fx << " ";
	for (auto const& [key, cnt] : ys)
		if (cnt & 1) {
			cout << key - fx;
			break;
		}
	cout << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}