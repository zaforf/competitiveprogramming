#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD=1e9+7;
const int MAXN=2e5+1;

ll exp(ll a,ll b) {
	ll ret = 1;
	a %= MOD;
	while (b) {
		if (b&1) ret = ret * a % MOD;
		a = a * a % MOD;
		b>>=1;
	}
	return ret;
}

ll fac[MAXN+1];
ll inv[MAXN+1];

void factorial() {
	fac[0] = 1;
	for (int i=1;i<MAXN+1;i++) fac[i] = fac[i-1]*i%MOD;
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN],MOD-2);
	for (int i=MAXN-1;i>=0;i--) inv[i] = inv[i+1]*(i+1)%MOD;
}

ll comb(ll a, ll b) {
	if (b>a || a<0 || b<0) return 1;
	return fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}


int main() {
	factorial();
	inverses();
	int n, m; cin>>n>>m;
	int ret = 1;
	for (int i=0;i<m;i++) {
		int inp; cin>>inp;
		ret = (ret * comb(inp,n)) % MOD;
	}
	cout << ret;
	return 0;
}