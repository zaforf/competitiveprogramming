#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;cin>>n>>k;
	int a[n], t[n];
	int ans = 0, c = 0;
	for (int& i : a) cin>>i;
	for (int& i : t) cin>>i;
	for (int i=0;i<n;i++) {
		if (!t[i]) c += a[i];
		if (i>=k && !t[i-k]) c -= a[i-k];
		ans  = max(ans,c);
	}
	for (int i=0;i<n;i++)
		if (t[i]) ans += a[i];
	cout << ans;
	return 0;
}