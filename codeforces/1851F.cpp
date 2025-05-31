#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,k; cin>>n>>k;
	vector<pair<int,int>> a(n);
	for (int i=0;i<n;i++) {
		cin>>a[i].first;
		a[i].second = i+1;
	}
	sort(a.begin(),a.end());
	int minxor=1<<k, minind;
	for (int i=0;i<n-1;i++) {
		if (minxor > (a[i].first ^ a[i+1].first)) {
			minxor = a[i].first ^ a[i+1].first;
			minind = i;
		}
	}
	int x = a[minind].first, y = a[minind+1].first;
	cout << a[minind].second << " " << a[minind+1].second << " " << (((1<<k)-1)&(~x & ~y)) << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}