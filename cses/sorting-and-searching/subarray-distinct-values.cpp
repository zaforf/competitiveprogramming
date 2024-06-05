#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int n,k;cin>>n>>k;
	int v[n];
	for (int& i : v) cin>>i;
	map<int,int> cnt;
	int a=0,ans=0;
	for (int i=0;i<n;i++) {
		cnt[v[i]]++;
		while (cnt.size()>k) {
			cnt[v[a]]--;
			if (!cnt[v[a]]) cnt.erase(v[a]);
			a++;
		}
		ans += i-a+1; // number of subarrays ending at i
	}
	cout << ans;
	return 0;
}