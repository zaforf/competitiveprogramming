#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD=1e9+7;
const int MAXN=2e5+1;

long long exp(long long a,long long b) {
	long long ret = 1;
	a %= MOD;
	while (b) {
		if (b&1) ret = ret * a % MOD;
		a = a * a % MOD;
		b>>=1;
	}
	return ret;
}

long long fac[MAXN+1];
long long inv[MAXN+1];

void factorial() {
	fac[0] = 1;
	for (int i=1;i<MAXN+1;i++) fac[i] = fac[i-1]*i%MOD;
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN],MOD-2);
	for (int i=MAXN-1;i>=0;i--) inv[i] = inv[i+1]*(i+1)%MOD;
}

long long comb(ll a, ll b) {
	if (b>a || a<0 || b<0) return 1;
	return fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}

void solve() {
	int n,k; cin>>n>>k;
	int c = 0; ll ans = 0;
	int mid = (k+1)/2;
	for (int i=0;i<n;i++) {
		int inp; cin>>inp;
		if (inp==1) c++;
	}
	if (k==1) {
		cout << c << '\n';
		return;
	}
	for (int i=mid;i<=k;i++) {
		if (i>c) break;
		if (k-i>n-c) continue;
		ans = (ans+comb(c,i)*comb(n-c,k-i))%MOD;
	}
	cout << ans << '\n';
}

int main() {
	factorial();
	inverses();
	int T; cin>>T;
	for (int i=0;i<T;i++) {
		solve();
	}
	return 0;
}