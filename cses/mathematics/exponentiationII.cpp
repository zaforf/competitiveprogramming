#include <bits/stdc++.h>
using namespace std;
#define int long long

int binexp(int a, int b, int MOD) {
	int ret=1;
	while (b) {
		if (b&1) {
			ret *= a;
			ret %= MOD;
		}
		a *= a;
		a %= MOD;
		b >>= 1;
	}
	return ret;
}

int MOD = 1000000007;

int32_t main() {
	int T;cin>>T;
	for (int i=0;i<T;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		cout<<binexp(a,binexp(b,c,MOD-1),MOD)<<endl;
	}
	return 0;
}