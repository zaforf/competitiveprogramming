#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;cin>>n;
	vector<int> a(n);
	for (int& i : a) cin>>i;
	int mn = a[0], mx = a[0], md;
	vector<int> ans;
	for (int i=0;i<n;i++) {
		mn = min(mn,a[i]);
		mx = max(mx,a[i]);
	}
	
	for (int z=0;z<40;z++) {
		if (mx==0) break;
		if ((mx-mn)%2) {
			cout << "-1\n";
			return;
		}
		md = (mn+mx)/2;
		ans.push_back(md);
		for (int i=0;i<n;i++) {
			a[i] = abs(a[i]-md);
			if (i==0) {
				mn = a[0];
				mx = a[0];
			}
			mn = min(mn,a[i]);
			mx = max(mx,a[i]);
		}
		
	}
	if (mx) {
		cout << "-1\n";
		return;
	}
	cout << ans.size() << "\n";
	for (int i : ans) cout << i << " ";
	cout << "\n";
}

int main() {
	int T;cin>>T;
	while (T --> 0) solve();
	return 0;
}