#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	int a[n]; for (int& i : a) cin>>i;
	int m; cin>>m;
	vector<int> last(n,-1);
	map<int,int> ind;
	for (int i=0;i<n;i++) {
		if (ind.find(a[i])!=ind.end())
			last[i] = ind[a[i]];
		ind[a[i]]=i;
	}
	
	for (int i=0;i<m;i++) {
		string s; cin>>s;
		if (s.size()!=n) {
			cout << "NO\n";
			continue;
		}
		map<int,int> c;
		bool bad = false;
		for (int i=0;i<n;i++) {
			if (c.find(s[i])!=c.end() && c[s[i]]!=a[i]) {
				cout<<"NO\n"; bad = true; break;
			}
			c[s[i]]=a[i];
			if (last[i]!=-1 && s[last[i]]!=s[i]) {
				cout<<"NO\n"; bad = true; break;
			}
		}
		if (!bad) cout <<"YES\n";
	}
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}