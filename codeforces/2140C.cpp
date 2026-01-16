#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n; cin>>n;
    vecin(a, n);
    int max_odd = INT_MIN, max_even = INT_MIN;
    int delta = 0;
    for (int i=0; i<n; i++) {
        if (i % 2 == 0) {
            delta = max(delta, max_odd - 2 * a[i] + i);
            delta = max(delta, i - 0);
        } else {
            delta = max(delta, max_even + 2 * a[i] + i);
            delta = max(delta, i - 1);
        }

        if (i % 2 == 0) {
            max_even = max(max_even, -2 * a[i] - i);
        } else {
            max_odd = max(max_odd, 2 * a[i] - i);
        }
    }
    int ans = 0;
    // calculate alternating sum
    for (int i=0; i<n; i++) {
        if (i % 2 == 0) {
            ans += a[i];
        } else {
            ans -= a[i];
        }
    }
    cout << ans + delta << endl;


}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}