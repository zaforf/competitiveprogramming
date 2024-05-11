#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;

int exp(int a,int b) {
	int ret = 1;
	a %= MOD; b%=MOD-1;
	while (b) {
		if (b&1) ret = ret * a % MOD;
		a = a * a % MOD;
		b>>=1;
	}
	return ret;
}

int32_t main() {
	int n,one,two,four;cin>>n;
	// number of 90 deg turns to appear the same
	if (n%2) {
		one = exp(2,n/2*(n/2+1)+1);
		two = exp(2,n*(n/2+1)-(n/2))-one; two %= MOD;
		four = exp(2,n*n)-one-two; four %= MOD;
	} else {
		one = exp(2,n/2*n/2);
		two = exp(2,n*n/2)-one; two %= MOD;
		four = exp(2,n*n)-one-two; four %= MOD;
	}
	cout << (one + two*exp(2,MOD-2)%MOD + four*exp(4,MOD-2)%MOD)%WMOD << endl;
	return 0;
}