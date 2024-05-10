#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;

int exp(int a,int b) {
	int ret = 1;
	a %= MOD;
	while (b) {
		if (b&1) ret = ret * a % MOD;
		a = a * a % MOD;
		b>>=1;
	}
	return ret;
}

int32_t main() {
	int n,k,ans=0;cin>>n>>k;
	for (int i=0;i<n;i++) ans = (ans+exp(k,gcd(i,n)))%MOD;
	cout<<ans*exp(n,MOD-2)%MOD;
	return 0;
}