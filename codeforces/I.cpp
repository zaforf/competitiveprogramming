#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
int p[MAXN] , pref[MAXN] , apref[MAXN];

int main() {
	random_device rd;
	mt19937_64 eng(rd());
	uniform_int_distribution<long long> distr;
	int n, q; cin>>n>>q;
	for (int i=1;i<=n;i++) p[i] = distr(eng);
	for (int i=0;i<n;i++) {
		int inp; cin>>inp;
		if (i==0) {
			apref[i] = p[inp];
			pref[i+1] = p[i+1];
		} else {
			apref[i] = apref[i-1]^p[inp];
			pref[i+1] = pref[i]^p[i+1];
		}
	}
	for (int i=0;i<q;i++) {
		int l,r; cin>>l>>r; l--; r--;
		int axor = apref[r]^(l ? apref[l-1] : 0);
		int pxor = pref[r+1]^pref[l];
		if (axor == pxor)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}