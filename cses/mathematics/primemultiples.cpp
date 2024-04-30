#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int n,k;cin>>n>>k;
	vector<int> primes(k);
	for (int i=0;i<k;i++) cin>>primes[i];
	int ans=0;
	for (int mask=1;mask<(1<<k);mask++) {
		int prod=n;
		for (int i=0;i<k;i++) {
			if (1<<i & mask) {
				prod /= primes[i];
			}
		}
		if (__builtin_popcount(mask)%2==0)
			prod *= -1;
		ans += prod;
	}
	cout<<ans<<endl;
	return 0;
}