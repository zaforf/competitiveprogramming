#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int T; cin>>T;
	while (T --> 0) {
		int n; ll x;
		cin >> n >> x;
		vector<ll> a(n+1);
		for (int i=1;i<=n;i++) cin>>a[i];
		partial_sum(a.begin()+1,a.end(),a.begin()+1);
		vector <int> dp(n+2);
		for (int i=n-1;i>=0;i--) {
			int f = upper_bound(a.begin(),a.end(),a[i]+x)-a.begin();
			dp[i] = dp[f] + (f-1) - i;
		}
		cout << accumulate(dp.begin(),dp.end(), 0ll) << '\n';
	}
	return 0;
}