#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	vector<int> cnt(n+1), dup;
	for (int i=0;i<n;i++) {
		if (cnt[a[i]] || a[i]==n) dup.push_back(i);
		cnt[a[i]]++;
	}
	int p = 0;
	vector<int> ans;
	for (int i=0;i<n;i++) {
		if (cnt[i] == 0) {
			ans.push_back(dup[p]);
			a[dup[p++]] = i;
		}
	}
	for (int i=0;i<n;i++) {
		if (a[i] != i) {
			ans.push_back(i);
			while (a[i] != i) {
				ans.push_back(a[i]);
				swap(a[i],a[a[i]]);		
			}
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (int x : ans) cout << x+1 << " ";
	cout << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}