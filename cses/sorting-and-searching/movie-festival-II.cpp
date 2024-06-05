#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

int main() {
	int n,k;cin>>n>>k;
	vector<pii> movies(n);
	for (pii& i : movies)
		cin>>i.f>>i.s;
	sort(movies.begin(),movies.end(),[](pii a, pii b) {
		return (a.s==b.s ? a.f<b.f : a.s<b.s);
	});

	multiset<int> endtimes;
	int ans=0; auto it = endtimes.begin();
	for (int i=0;i<n;i++) {
		if (endtimes.size()) it = endtimes.upper_bound(movies[i].f);
		if (it!=endtimes.begin()){
			it--;
			endtimes.erase(it);
			endtimes.insert(movies[i].s);
			ans++;
		} else if (endtimes.size()<k) {
			endtimes.insert(movies[i].s);
			ans++;
		}
	}
	cout << ans;
	return 0;
}