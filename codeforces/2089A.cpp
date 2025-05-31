#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1000001;
int sieve[MAXX];

void solve() {
	int n; cin>>n;
	int x;
	for (x=n/2;x<n;x++)
		if (!sieve[x])
			break;
	int l = x-1, r = x+1;
	cout << x << " ";
	for (int i=1;i<n;i++) {
		if (l == 0)
			cout << r++ << " ";
		else if ((r == n+1) || (i & 1)) 
			cout << l-- << " ";
		else
			cout << r++ << " ";
	}
	cout << endl;
}

int main() {
	int T;cin>>T;
	for (int i=2;i<MAXX;i++)
		if (!sieve[i])
			for (int j=2*i;j<MAXX;j+=i)
				sieve[j]=i;

	while (T --> 0) {
		solve();
	}
	return 0;
}