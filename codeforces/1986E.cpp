#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

void solve() {
	int n,k; cin>>n>>k;
	map<int,vector<int>> mp;
	for (int i=0;i<n;i++) {
		int inp; cin>>inp;
		mp[inp%k].push_back(inp);
	}
	int ans = 0;
	bool odd = 0;
	for (auto& [m,v] : mp) {
		sort(v.begin(),v.end());
		if (v.size()&1) {
			if (odd || n&1^1) {
				cout << "-1\n";
				return;
			} else odd = true;
			int n = v.size();
			vector<int> bef(n),aft(n);
			for (int i=1;i<n;i++) {
				bef[i] = bef[i-1];
				if (i&1) bef[i] += v[i]-v[i-1];
			}
			for (int i=n-2;i>=0;i--) {
				aft[i] = aft[i+1];
				if (i&1) aft[i] += v[i+1]-v[i];
			}
			int best = 1e9;
			for (int i=0;i<n;i++) {
				if (i&1) best = min(best,bef[i-1]+aft[i+1]+v[i+1]-v[i-1]);
				else best = min(best,bef[i]+aft[i]);
			}
			ans += best/k;
		} else {
			for (int i=1;i<v.size();i+=2)
				ans += (v[i]-v[i-1])/k;
		}
	}
	cout << ans << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}