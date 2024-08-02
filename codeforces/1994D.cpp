#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while (T --> 0) {
		int n; cin>>n;
		int a[n]; for (int& i : a) cin>>i;
		set<int> rep;
		for (int i=0;i<n;i++) rep.insert(i);

		cout << "YES\n";
		vector<pair<int,int>> ans;
		for (int i=n-1;i;i--) {
			vector<int> occ(i,-1);
			for (const int& j : rep) {
				if (occ[a[j]%i] != -1) {
					ans.push_back({j,occ[a[j]%i]});
					rep.erase(j);
					break;
				}
				occ[a[j]%i] = j;
			}
		}
		reverse(ans.begin(),ans.end());
		for (auto [a,b] : ans) cout << a+1 << " " << b+1 << '\n';
	}
	return 0;
}