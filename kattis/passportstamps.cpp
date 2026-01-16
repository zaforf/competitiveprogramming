#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int32_t main() {
    int n, p; cin >> n >> p;
    vecin(a, n);
    int ans = n;
    vector<int> prefix(n, 0);
    for (int i = 0; i < n; i++) {
        prefix[i] = a[i] + (i > 0 ? prefix[i-1] : 0);
    }
    for (int m = 0; m < n; m++) {
        int d = (a[m] > 1) ? (p / (a[m]-1)) : n+1;
        if (d < m) {
            ans = m;
            break;
        }
        if (prefix[m] - a[m] >= p) {
            ans = m;
            break;
        }
        int s = (m+1)*(a[m]-1) + prefix[m] - a[m];
        if (s >= p) {
            ans = m;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}