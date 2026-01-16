#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n; cin>>n;
    vecin(a,n);
    int ans = n;
    vector<bool> left_bound(n, false);
    for (int i=n-2;i>=0;i--) {
        int aft = a[i+1];
        if (a[i] > aft && !left_bound[i+1]) {
            if (i==0 || (a[i-1] < a[i] && a[i-1] > aft)) {
                left_bound[i] = true;
                ans += (n - i);
            } else {
                ans += (i + 1) * (n - i);
            }
        }
        if (i + 2 < n && !left_bound[i+2]) {
            aft = a[i+2];
            if (a[i] > aft) {
                if (a[i+1] < aft || a[i] < a[i+1]) {
                    ans += (left_bound[i] ? 1 : (i + 1)) * (n - (i + 2));
                }
            }
        }
    }
    vecout(left_bound);

    cout << ans << endl;

}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}