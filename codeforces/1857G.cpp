#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 200001;
const int MOD = 998244353;
vector<int> e(MAXN,-1);

int get(int x) { return (e[x]<0 ? x : e[x]=get(e[x])); }

int merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a==b) return MOD - 2;
	if (e[a]>e[b]) swap(a,b);
	int l = -e[a], r = -e[b];
	e[a] += e[b];
	e[b] = a;
	return (l*r - 2 + MOD) % (MOD - 1);
}

int sz(int x) {return -e[get(x)];}

#define ppi pair<int,pair<int,int>>
#define f first
#define s second

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

void solve() {
	int n,s; cin>>n>>s;
	priority_queue<ppi> pq;

	for (int i=0;i<n-1;i++) {
		int a, b, w; cin>>a>>b>>w;
		pq.push({-w,{a,b}});
	}
	int last = 0, ans = 1, curr = 0;
	while (pq.size()) {
		ppi c = pq.top(); pq.pop();
		int a = c.s.f, b = c.s.s, w = -c.f;
		if (w > last) {
			ans = ans * binexp(s - last + 1, curr) % MOD;
			last = w;
			curr = 0;
		}
		curr = (curr + merge(a,b) + MOD - 1) % (MOD - 1);
	}
	ans = ans * binexp(s - last + 1, curr) % MOD;

	for (int i=1;i<=n;i++) e[i] = -1;
	cout << ans << endl;
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}