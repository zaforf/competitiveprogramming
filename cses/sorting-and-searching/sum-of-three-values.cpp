#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f first
#define s second

int32_t main() {
	int n,x;cin>>n>>x;
	vector<pii> v(n);
	for (pii& i : v) cin>>i.f;
	for (int i=0;i<n;i++) v[i].s=i;
	sort(v.begin(),v.end());
	bool f=false;
	int a,b,c;
	for (c=n-1;c>=0;c--) {
		if (v[c].f>x) continue;
		a=0,b=c-1;
		while (a<b)
			if (v[a].f+v[b].f+v[c].f==x) {
				f = true;
				break;
			} else if (v[a].f+v[b].f+v[c].f > x)
				b--;
			else
				a++;
		if (f) break;
	}
	if (f)
		cout << v[a].s+1 << " " << v[b].s+1 << " " << v[c].s+1;
	else
		cout << "IMPOSSIBLE";
	return 0;
}