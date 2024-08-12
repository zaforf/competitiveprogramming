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

void solve() {
	ll n,k; cin>>n>>k;
	if (k==0) {
		cout << "1\n";
		return;
	}
	if (n&1) {
		cout << exp(exp(2,n-1)+1,k)%MOD << '\n';
	} else {
		ll equal = exp(exp(2,n-1)-1,k);
		ll ans = exp(2, n*k) - equal;
		ans = ans*exp(exp(2,n-1)+1,MOD-2)%MOD;
		ans = (ans + equal) % MOD;
		while (ans<0) ans += MOD;
		cout << ans%MOD << '\n';
	}
	
}

int main() {
	int T;cin>>T;
	factorial();
	inverses();
	while (T --> 0) {
		solve();
	}
	return 0;
}