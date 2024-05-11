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
	// n: # open brackets not in prefix
	// k: # open brackets in prefix
	bool ok=true;
	int n,k=0;cin>>n;
	if (n%2) ok=false;
	n/=2;
	string s; cin>>s;
	for (char& c : s)
		if (c==')') {
			k--;n--;
			if (k<0) ok=false;
		} else k++;
	n-=k;
	if (!ok) {
		cout << 0;
		return 0;
	}
	// (k+1)/(n+k+1) * nCr(2n+k,n)
	cout << (k+1)*exp(n+k+1,MOD-2)%MOD*fac[2*n+k]%MOD*inv[n]%MOD*inv[n+k]%MOD << "\n";
	return 0;
}
