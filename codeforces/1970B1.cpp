#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

int main() {
	int n; cin >> n;
	vector<pii> ps;
	for (int i=0;i<n;i++) {
		int inp; cin >> inp;
		ps.push_back({inp, i});
	}
	sort(ps.begin(), ps.end(), greater<pii>());
	int skip = 0;
	for (int i=0;i<n-1;i++) {
		if (ps[i].f == ps[i+1].f) {
			skip = i;
			break;
		}
	}
	vector<pii> locs(n);
	vector<int> pair(n);

	locs[ps[skip+1].s] = {2,1};
	locs[ps[skip].s] = {1,max(1,ps[skip].f)};
	if (ps[skip+1].f == 0) {
		pair[ps[skip].s] = ps[skip].s;
	} else {
		pair[ps[skip].s] = ps[skip+1].s;
	}
	if (ps[skip+1].f == 0) {
		pair[ps[skip+1].s] = ps[skip+1].s;
	} else {
		pair[ps[skip+1].s] = ps[skip].s;
	}
	int left = ps[skip+1].s;
	int up = 1;
	for (int i=0;i<n;i++) {
		if (i == skip || i == skip + 1) continue;
		locs[ps[i].s] = locs[left];
		locs[ps[i].s].f++;
		locs[ps[i].s].s += up * max(0, (ps[i].f - 1));
		if (ps[i].f == 0)
			pair[ps[i].s] = ps[i].s;
		else	
			pair[ps[i].s] = left;
		left = ps[i].s;
		up = -up;
	}
	cout << "YES\n";
	for (int i=0;i<n;i++) {
		cout << locs[i].f << " " << locs[i].s << endl;
	}
	for (int i=0;i<n;i++)
		cout << pair[i]+1 << " ";

	return 0;
}