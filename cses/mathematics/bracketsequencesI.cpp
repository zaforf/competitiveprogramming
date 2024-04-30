#include <bits/stdc++.h>
using namespace std;
 
const int MOD=1e9+7;
const int MAXN=2e6;
 
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
 
int main() {
	factorial();
	inverses();
	int n;cin>>n;
	if (n%2) cout << 0 << "\n";
	else cout << exp(n/2+1,MOD-2)*fac[n]%MOD*inv[n/2]%MOD*inv[n/2]%MOD << "\n";
	return 0;
}
