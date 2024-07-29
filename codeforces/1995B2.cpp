#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
#define f first
#define s second

int32_t main() {
	int T; cin>>T;
	while (T-->0) {
		int n;
		int m;cin>>n>>m;
		int a[n]; unordered_map<int,int> freq;
		for (int& i : a) cin>>i;
		for (int i=0;i<n;i++) cin >> freq[a[i]];
		sort(a,a+n);
		int ans=0;
		for (int i=0;i<n;i++) {
			int c = a[i], tot = m;
			int k1 = min(freq[c],tot/c);
			tot -= k1*c;
			int k2 = min(freq[c+1],tot/(c+1));
			tot -= k2*(c+1);
			int r = min(min(k1,freq[c+1]-k2),tot);
			ans = max(ans,(int) (k1-r)*c+(k2+r)*(c+1));
		}
		cout << ans << '\n';
	}
	return 0;
}