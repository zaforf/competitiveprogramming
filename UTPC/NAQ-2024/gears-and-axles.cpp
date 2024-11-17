#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	map<int,vector<int>> m;
	for (int i=0;i<n;i++) {
		int s,c;cin>>s>>c;
		m[s].push_back(c);
	}
	double ans = 0;
	for (auto s : m) {
		vector<int> v = s.second;
		sort(v.begin(),v.end());
		int l = 0, r = (int) v.size() -1;
		while (l<r) {
			ans += log(v[r]);
			ans -= log(v[l]);
			l++;
			r--;
		}
	}
	cout << setprecision(10) << ans;
	return 0;
}