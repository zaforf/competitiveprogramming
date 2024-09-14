#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN=501;

ll exp(ll a,ll b, ll MOD) {
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
ll pow2[MAXN+1];

void factorial(ll MOD) {
	fac[0] = 1;
	for (int i=1;i<MAXN+1;i++) fac[i] = fac[i-1]*i%MOD;
}

void inverses(ll MOD) {
	inv[MAXN] = exp(fac[MAXN],MOD-2,MOD);
	for (int i=MAXN-1;i>=0;i--) inv[i] = inv[i+1]*(i+1)%MOD;
}

void powers(ll MOD) {
	pow2[0] = 1;
	for (int i=1;i<MAXN+1;i++) pow2[i] = pow2[i-1]*2%MOD;
}

ll comb(ll a, ll b, ll MOD) {
	if (b>a || a<0 || b<0) return 1;
	return fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}

void solve() {
	ll n,k,p; cin>>n>>k>>p;
	factorial(p); inverses(p); powers(p);

	vector<vector<ll>> dp(n, vector<ll>(k+1,0));
	for (int j=0;j<=k;j++) dp[0][j] = 1;
	for (int i=1;i<n;i++) {
		for (int j=0; j<=k; j++) {
			for (int x=0; x<j && x+j <= k; x++) {
				dp[i][j+x] = (dp[i][j+x] + dp[i-1][j]*comb(x+(pow2[i]-1)-1,x,p)%p) % p;
			}

		}
		for (int j=1; j<=k; j++)
			dp[i][j] = (dp[i][j] + dp[i][j-1]) % p;
	}
	cout << dp[n-1][k] * pow2[n-1] % p << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}