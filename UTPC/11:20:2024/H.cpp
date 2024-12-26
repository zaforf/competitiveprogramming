#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
#define int long long
const int MAXN = 200001;

vector<int> e(MAXN,-1);

int get(int x) { return (e[x]<0 ? x : e[x]=get(e[x])); }

bool merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a==b) return false;
	if (e[a]>e[b]) swap(a,b);
	e[a] += e[b];
	e[b] = a;
	return true;
}

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

int sz(int x) {return -e[get(x)];}

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

int32_t main() {
	factorial();
	inverses();
	int n, m; cin>>n>>m;
	int groups = n; int ans = 1;
	for (int i=0;i<m;i++) {
		int x,y; cin>>x>>y;
		int a = get(x);
		int b = get(y);
		if (a==b) {
			cout << groups << " " << (ans*fac[groups])%MOD << endl;
			continue;
		}
		ans = (ans*inv[sz(a)])%MOD;
		ans = (ans*inv[sz(b)])%MOD;
		groups--;
		merge(x,y);
		ans = (ans*fac[sz(x)])%MOD;
		cout << groups << " " << (ans*fac[groups])%MOD << endl;
	}

	
	return 0;
}