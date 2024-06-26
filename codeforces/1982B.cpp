#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		int x,y,k;cin>>x>>y>>k;
		int to_next_multiple = y - (x%y);
		while (x!=1 && to_next_multiple <= k) {
			k -= to_next_multiple;
			x += to_next_multiple;
			while (x%y==0) x/=y;
			to_next_multiple = y - (x%y);
		}
		if (to_next_multiple>k) {
			cout << x+k << endl;
		} else {
			cout << x+(k%(y-1)) << endl;
		}
	}
	return 0;
}