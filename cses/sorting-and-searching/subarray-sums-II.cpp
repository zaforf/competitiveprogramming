#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int n,x;cin>>n>>x;
	int v[n];
	for (int& i : v) cin>>i;
	unordered_map<int,int> cnt;
	cnt[0]=1;
	int s=0,ans=0;
	for (int i=0;i<n;i++) {
		s += v[i];
		if (cnt.find(s-x)!=cnt.end())
			ans += cnt[s-x];
		cnt[s]++;
	}
	cout << ans;
	return 0;
}