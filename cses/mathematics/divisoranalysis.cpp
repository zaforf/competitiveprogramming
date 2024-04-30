#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MOD = 1000000007;
#define int long long

int binexp(int a, int b) {
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


int32_t main() {
	vector<pair<int,int>> pf;
	int N; cin>>N;
	for (int i=0;i<N;i++) {
		int a,b;cin>>a>>b;
		pf.push_back({a,b});
	}
	int numd=1,sumd=1,prodd=1,pnumd=1;
	for (int i=0;i<N;i++) {
		numd *= pf[i].s+1 % MOD; numd %= MOD;
		sumd *= (binexp(pf[i].f,pf[i].s+1)-1)*binexp(pf[i].f-1,MOD-2) % MOD; sumd %= MOD;
		prodd = binexp(prodd,pf[i].s+1) * binexp(binexp(pf[i].f,(pf[i].s+1)*pf[i].s/2),pnumd) % MOD; prodd %= MOD;
		pnumd *= pf[i].s+1 % (MOD-1); pnumd %= MOD-1;
	}
	cout << numd << " " << sumd << " " << prodd << endl;
	return 0;
}