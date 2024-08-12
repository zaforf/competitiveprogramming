#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n,k,use=1; cin>>n>>k;
	int a[n]; for (int& i : a) cin>>i;
	int b[n]; for (int i=0;i<n;i++) b[i]=a[i];
	sort(b,b+n);
	map<int,int> ind;
	for (int i=0;i<n;i++) ind[b[i]]=i;
	for (int i=1;i<n;i++)
		if (ind[a[i]]!=ind[a[i-1]]+1) use++;
	cout << (use<=k? "YES" : "NO") << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}