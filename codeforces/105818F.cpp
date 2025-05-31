#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int MAXN = 1000001;

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

int fac[MAXN+1];
int inv[MAXN+1];

void factorial() {
	fac[0] = 1;
	for (int i=1;i<MAXN+1;i++) fac[i] = fac[i-1]*i%MOD;
}

void inverses() {
	inv[MAXN] = exp(fac[MAXN],MOD-2);
	for (int i=MAXN-1;i>=0;i--) inv[i] = inv[i+1]*(i+1)%MOD;
}

int comb(int a, int b) {
	if (b>a || a<0 || b<0) return 0;
	return fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}

void solve() {
	factorial();
	inverses();
	string s; cin>>s;
	int pop = 0, l = s.size();
	for (int i=0;i<l;i++)
		if (s[i]=='1') pop++;
	int ans = 0;
	int goof = 0;
	for (int i=0;i<=l-pop;i++) {
		goof = (goof + comb(l-1, i)) % MOD;
	}
	cout << goof << endl;
	ans += goof;
	pop--;
	for (int i=1;i<l;i++) {
		goof = (goof + comb(l-i-2, i)) / 2 % MOD;
		cout << goof << endl;
		if (s[i]=='1') {
			ans = (ans + goof) % MOD;
		}
	}
	cout << ans << "---" << endl;
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}