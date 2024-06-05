#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f first
#define s second

int32_t main() {
	int n,x;cin>>n>>x;
	int v[n];
	map<int,pii> hash;
	for (int& i : v) cin>>i;
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			if (hash.find(x-v[i]-v[j])!=hash.end()) {
				cout << hash[x-v[i]-v[j]].f+1 << " " << hash[x-v[i]-v[j]].s+1 << " " << i+1 << " " << j+1 << endl;;
				return 0;
			}
		}
		for (int j=i-1;j>=0;j--)
			hash[v[i]+v[j]] = {j,i};
	}
	cout << "IMPOSSIBLE";
	return 0;
}