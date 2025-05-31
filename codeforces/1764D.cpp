#include <bits/stdc++.h>
using namespace std;

#define int long long
int MOD;
const int MAXN = 5001;

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

int32_t main() {
	int n; cin>>n>>MOD;
	factorial(); inverses();
	int half = (n + 1) / 2;
	vector<int> end_amts(half+1);
	int ans = 0;
	for (int i=half;i>0;i--) {
		int val = comb(half-1, i-1);
		val = ((val * fac[n-i]) % MOD * n) % MOD;
		for (int j=i+1;j<=half;j++)
			val = (val - end_amts[j]*fac[j]%MOD*inv[i]%MOD + MOD) % MOD;
		end_amts[i] = val;
		ans = (ans + val) % MOD;
	}
	cout << ans << endl;
	return 0;
}