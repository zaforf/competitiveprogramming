#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	while (T-->0) {
		int n, ans = 0; cin>>n;
		int a[n]; for (int& i : a) cin>>i;
		bool b12 = 0, b34 = 0;
		for (int i=0;i<n;i++) {
			if ((!b12) && (!b34)) {
				if (a[i]==0) continue;
				ans++;
				if (a[i]<=2) b12=1;
			} else if (b12) {
				b12 = 0;
				if (a[i]<=2) continue;
				ans++;
				if (a[i]<=4) b34=1;
			} else {
				b34 = 0;
				if (a[i]==0) continue;
				ans++;
				if (a[i]<=4) b12=1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}