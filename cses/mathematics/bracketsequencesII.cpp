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
	int n,down=0;cin>>n;
	if (n%2==1) {
		cout << 0 << "\n";
		return 0;
	}
	string s; cin>>s;
	for (int i=0;i<s.length();i++) {
		if (s[i]=='(') down++;
		else down--;
		if (down<0) {
			cout << 0 << "\n";
			return 0;
		}
	}
	n = n-s.length()-down;
	int ans = fac[n/2+1]*inv[down]%MOD*inv[down]*inv[n/2+1-down]%MOD;
	cout<<ans <<" " << n << endl;
	cout << exp(n/2+1,MOD-2)%MOD*fac[n]%MOD*inv[n/2]%MOD*inv[n/2]%MOD << endl;
	ans = ans*exp(n/2+1,MOD-2)%MOD*fac[n]%MOD*inv[n/2]%MOD*inv[n/2]%MOD;
	cout << ans << "\n";
	return 0;
}
