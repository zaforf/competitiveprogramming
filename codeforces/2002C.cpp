#include <bits/stdc++.h>
using namespace std;
#define pii pair<long long, long long>
#define ll long long
#define f first
#define s second

void solve() {
	int n; cin>>n;
	vector<pii> circles(n);
	for (pii& p : circles)
		cin >> p.f >> p.s;
	pii s, e;
	cin>>s.f>>s.s>>e.f>>e.s;
	ll minsq = LLONG_MAX;
	for (pii& p : circles)
		minsq = min(minsq,(e.s-p.s)*(e.s-p.s)+(e.f-p.f)*(e.f-p.f));
	if (minsq>(e.s-s.s)*(e.s-s.s)+(e.f-s.f)*(e.f-s.f))
		cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}