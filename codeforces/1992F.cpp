#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
bool used[MAXN];
bool divs[MAXN];

void solve() {
	int n,x;cin>>n>>x;
	int a[n]; for (int& i : a) cin >> i;
	vector<int> ds;
	for (int i=1;i*i<=x;i++) {
		if (x%i==0) {
			divs[i] = true;
			divs[x/i] = true;
			ds.push_back(i);
			if (i*i<x) ds.push_back(x/i);
		}
	}
	vector<int> curr(1,1); int ans=1;
	for (int i=0;i<n;i++) {
		if (!divs[a[i]]) continue;
		for (int d : curr) if (1ll*d*a[i]==x) {
			ans++;
			for (int d : curr) used[d] = false;
			used[1] = true;
			curr.clear();
			curr.push_back(1);
			break;
		}
		int sz = curr.size();
		for (int j=0;j<sz;j++) {
			if (1ll*curr[j]*a[i]<=x && !used[curr[j]*a[i]] && divs[curr[j]*a[i]]) {
				curr.push_back(curr[j]*a[i]);
				used[curr[j]*a[i]] = true;
			}
		}
	}
	for (int d : ds) {
		used[d] = false;
		divs[d] = false;
	}
	cout << ans << '\n';
}

int32_t main() {
	int T; cin>>T;
	while (T-->0) solve();
	return 0;
}