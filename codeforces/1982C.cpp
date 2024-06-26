#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		int n,l,r;cin>>n>>l>>r;
		int a[n],pfix[n+1];
		for (int& i : a) cin >> i;
		for (int i=0;i<n;i++) pfix[i+1]=pfix[i]+a[i];
		int p1=0,p2=0,ans=0;
		while (p2<=n) {
			while (p2+1<=n && pfix[p2]-pfix[p1]<l) p2++;
			if (pfix[p2]-pfix[p1] >= l)
				if (pfix[p2]-pfix[p1] <= r) {
					ans++;p1=p2;
				} else {
					p2--;p1++;
				}
			p2++;
		}
		cout << ans << endl;
	}
	return 0;
}