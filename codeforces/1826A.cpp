#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n;cin>>n;
	vector<int> vals(n);
	for (int i=0;i<n;i++)
		cin>>vals[i];
	for (int i=0;i<=100;i++) {
		int cnt=0;
		for (int num : vals)
			if (num>i)
				cnt++;
		if (cnt==i) {
			cout<<i<<"\n";
			return 0;
		}
	}
	cout<<-1<<"\n";
	return 0;
}

int main() {
	int T; cin>>T;
	while (T--) {
		solve();
	}
	return 0;
}
