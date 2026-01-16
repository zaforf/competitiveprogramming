#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;
using ll = long long;

int main() {
    ll n, k, p; cin >> n >> k >> p;
    vector<ll> ans;
    for (ll i = 1; i*i <= n; i++) {
        ll a = i, b = n/a;
        if (a*b==n) {
            if (a <= k && b <= p) ans.push_back(a);
            if (b <= k && a <= p && a != b) ans.push_back(b);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto x : ans) cout << x << endl;

    return 0;
}