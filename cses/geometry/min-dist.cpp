#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second

int sq(int x) {
	return x*x;
}

int32_t main() {
	int n; cin>>n;
	vector<pair<int,int>> pts(n);
	for (pair<int,int>& i : pts)
		cin>>i.f>>i.s;
    sort(pts.begin(), pts.end());
    set<pair<int, int>> s;

    int ans = 8e18;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        int d = ceil(sqrt(ans));
        for (;pts[i].f - pts[j].f >= d;j++)
            s.erase({pts[j].s, pts[j].f});
    	
        auto it1 = s.lower_bound({pts[i].s - d, pts[i].f});
        auto it2 = s.upper_bound({pts[i].s + d, pts[i].f});
        
        for (auto it = it1; it != it2; ++it) 
            ans = min(ans,sq(pts[i].f-it->s) + sq(pts[i].s-it->f));      
        s.insert({pts[i].s, pts[i].f}); 
    }
    cout<<ans;
	return 0;
}