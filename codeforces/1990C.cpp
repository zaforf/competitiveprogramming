#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2e5+1;
vector<bool> cnt(MAXN);

int main() {
	int T; cin>>T;
	while (T --> 0) {
		int n; cin>>n;
		vector<int> a(n);
		for (int& i : a) cin>>i;
		int c = 0; ll ans = 0;

		fill(cnt.begin(),cnt.end(),false);
		for (int i=0;i<n;i++) {
			ans += a[i];
			if (cnt[a[i]]) c = max(c,a[i]);
			cnt[a[i]] = true;
			a[i] = c;
		}

		fill(cnt.begin(),cnt.end(),false);
		c = 0;
		for (int i=0;i<n;i++) {
			ans += a[i];
			if (cnt[a[i]]) c = max(c,a[i]);
			cnt[a[i]] = true;
			a[i] = c;
		}

		for (int i=0;i<n;i++) {
			ans += a[i]*1ll*(n-i);
		}
		cout << ans << '\n';
	}
	return 0;
}