#include <bits/stdc++.h>
#define ll long long
const ll M = 1e9 + 7;

using namespace std;
using pi = pair<int,int>;
pair<ll,ll> goal; pair<ll,ll> start;
#define f first
#define s second

ll firstTrue(ll lo, ll hi, function<bool(ll)> f) {
	hi++;
	while (lo<hi) {
		ll mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid+1;
		}
	}
	return lo;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>start.f>>start.s>>goal.f>>goal.s;
    int n; string str; cin >> n >> str;
    vector<pair<ll,ll>> prefix;
    for (auto c : str) {
        if (prefix.size()==0) {
            ll x = (c=='L') ? -1 : ((c=='R') ? 1 : 0);
            ll y = (c=='D') ? -1 : ((c=='U') ? 1 : 0);
            prefix.push_back(make_pair(x,y));
        }
        else {
            ll x = prefix[prefix.size()-1].f+((c=='L') ? -1 : ((c=='R') ? 1 : 0));
            ll y = prefix[prefix.size()-1].s+((c=='D') ? -1 : ((c=='U') ? 1 : 0));
            prefix.push_back(make_pair(x,y));
        }
    }
    ll ans = firstTrue(0,1e14, [&] (ll x) {
        pair<ll,ll> at; auto last = prefix.size()-1;
        at.f = prefix[last].f*(x/n)+((x%n-1>=0) ? prefix[x%n-1].f : 0);
        at.s = prefix[last].s*(x/n)+((x%n-1>=0) ? prefix[x%n-1].s : 0);
        return (abs(goal.f-(start.f+at.f))+abs(goal.s-(start.s+at.s))<=x);
    });
    cout << ((ans==100000000000001) ? -1 : ans) << endl;
}

/* 0 0
4 6
3
UUU 
*/
