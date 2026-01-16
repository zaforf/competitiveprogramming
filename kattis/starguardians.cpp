#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int32_t main() {
    int n; cin >> n;
    vecin(a, n);
    vecin(b, n);
    double ans = 0;
    for (int i=1;i<(1<<n);i++) {
        // sum b corresponding to set bits
        int sum_b = 0;
        for (int j=0;j<n;j++) {
            if (i & (1<<j)) sum_b += b[j];
        }
        sum_b += a[__builtin_popcount(i)-1];
        ans = max(ans, (double)sum_b / (double)(__builtin_popcount(i)));
    }
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}