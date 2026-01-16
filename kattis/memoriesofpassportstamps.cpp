#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int32_t main() {
    int n, k; cin >> n >> k;
    vecin(a, n);
    int l = 1, r = 1e18, ans = 1e18;
    while (l <= r) {
        int m = l + (r - l) / 2;
        int c = 0;
        for (auto x : a) {
            c += (x + m-1) / m;
            if (c > k) break;
        }
        if (c > k) {
            l = m + 1;
        } else {
            // cout << c << " " << m << endl;
            ans = min(ans, m);
            r = m - 1;
        }
    }
    cout << ans << endl;
    return 0;
}