#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXX = 1000001;
int sieve[MAXX];

int32_t main() {
	int n;cin>>n;int ans = n*(n-1)/2;
	vector<int> list(n);
	for (int& i : list) cin>>i;
	for (int i=2;i<MAXX;i++)
		if (!sieve[i])
			for (int j=i;j<MAXX;j+=i)
				sieve[j]=i;
	vector<int> cnt(MAXX,0);
	for (int x : list) {
		vector<int> ps;
		while (x>1) {
			int d = sieve[x]; ps.push_back(d);
			while (x%d==0) x/=d;
		}
		int k = ps.size();
		for (int mask=1;mask<(1<<k);mask++) {
			int prod=1;
			for (int j=0;j<k;j++)
				if (1<<j & mask)
					prod *= ps[j];
			ans-= cnt[prod]*(__builtin_popcount(mask)%2?1:-1);
			cnt[prod]++;
		}
	}
	cout<<ans<<endl;
	return 0;
}