#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;
long double t;

using namespace std;
using vi = vector<int>;
using pi = pair<int,int>;
long double firstTrue(long double lo, long double hi, function<bool(long double)> f) {
	hi++;
	while (abs(hi-lo)>1e-6) {
		long double mid = lo + (hi - lo) / 2.0;
        t = mid;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return lo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n; vector<pair<long double,long double>> friends(n);
    for (int i=0;i<n;i++) {
        cin>>friends[i].first;
    }
    for (int i=0;i<n;i++) {
        cin>>friends[i].second;
    }
    cout << setprecision(11) << fixed << firstTrue(0.0,1e9, [&] (long double x) {
        long double left=0.0; long double right=1e9+1.0;
        for (int i=0;i<n;i++) {
            long double e=friends[i].first+(friends[i].second*x);
            right = min(right,e);
            left = max(left,friends[i].first-friends[i].second*x);
        }
        return left<=right;
    }) << endl;
}