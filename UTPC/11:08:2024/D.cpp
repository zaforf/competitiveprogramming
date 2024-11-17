#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,w,b; cin>>n>>w>>b;
	if (w==b && b==0) {
		if (n==0) cout << "1";
		else cout << "0";
		return 0;
	}
	if (w==0) swap(w,b);
	if (b == 0) {
		cout << ((n % w) == 0 ? 1 : 0);
		return 0;
	}
	int ans = 0;
	for (int white = 0; white <= n; white += w) {
		if ((n - white) % b == 0) ans++;
	}
	cout << ans;
	return 0;
}