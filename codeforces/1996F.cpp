#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	while (T --> 0) {
		int n,k;cin>>n>>k;
		int a[n],b[n];
		for (int& i : a) cin>>i;
		for (int& i : b) cin>>i;

		int l=0,r=1e9+1,mid;
		long long c;
		while (l+1<r) {
			mid = r-(r-l)/2;
			c = 0;
			for (int i=0;i<n;i++)
				if (a[i]>=mid)
					c += (a[i]-mid)/b[i] + 1;
			if (c>=k) l = mid;
			else r = mid;
		}

		long long ans = 0, t;
		c = 0;
		for (int i=0;i<n;i++) {
			if (a[i]<mid) continue;
			t = (a[i]-mid)/b[i] + 1;
			c += t;
			ans += t*a[i]-t*(t-1)/2*b[i];
		}
		ans += l*(k-c);
		cout << ans << '\n';

	}
	return 0;
}