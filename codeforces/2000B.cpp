#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	int a[n]; for (int& i : a) cin >>i;
	vector<bool> occ(n+2);
	for (int i=0;i<n;i++) {
		if (i>0 && !occ[a[i]-1] && !occ[a[i]+1]) {
			cout<<"NO\n";
			return;
		}
		occ[a[i]]=true;
	}
	cout <<"YES\n";
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}