#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

int main() {
	int n,k,c; cin>>n>>k>>c;
	vector<pii> v(n);
	vector<bool> in(n);
	vector<int> team(n);
	for (pii& p : v)
		cin >> p.f >> p.s;
	int tot = 0;
	for (int i=0;i<n && tot<k;i++) {
		int t = v[i].s;
		if (team[t] < c) {
			in[i] = 1;
			team[t]++;
			tot++;
		}
	}
	if (tot < k) {
		for (int i=0;i<n && tot<k;i++) {
			if (in[i]) continue;
			in[i] = 1;
			tot++;
		}
	}
	for (int i=0;i<n;i++)
		if (in[i])
			cout << v[i].f << endl;
	return 0;
}