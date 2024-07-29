#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		string b; cin>>b;
		int n = b.size(), c=0, ans=0;
		vector<int> dp(2*n+1,0);
		dp[n] = 1;
		for (int i=0;i<n;i++) {
			if (b[i]=='1') c++;
			else c--;
			ans = (ans+dp[c+n]*(n-i))%MOD;
			dp[c+n] = (dp[c+n]+i+2)%MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}