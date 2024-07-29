#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while (T --> 0) {
		int n; cin>>n;
		int a[n];
		for (int& i : a) cin>>i;
		int mx = 0;
		for (int i=0;i<n;i+=2)
			mx = max(mx,a[i]);
		cout << mx << '\n';
	}
	return 0;
}