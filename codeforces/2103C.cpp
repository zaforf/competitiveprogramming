#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n, k; cin>>n>>k;
    vecin(a, n);
    for (int i=0;i<n;i++)
        if (a[i] <= k) a[i] = 1;
        else a[i] = 0;
    // find prefixes with atleast half 1s
    int prefix_ones = 0;
    int valid_prefixes = 0;
    int earliest_valid_prefix = n;
    for (int i=0;i<n;i++) {
        prefix_ones += a[i];
        if (prefix_ones * 2 >= i + 1) {
            if (a[i])
                valid_prefixes++;
            if (earliest_valid_prefix == n) {
                earliest_valid_prefix = i;
            }
        }
    }
    // do the same for suffixes
    int suffix_ones = 0;
    int valid_suffixes = 0;
    int latest_valid_suffix = -1;
    for (int i=n-1;i>=0;i--) {
        suffix_ones += a[i];
        if (suffix_ones * 2 >= n - i) {
            if (a[i])
                valid_suffixes++;
            if (latest_valid_suffix == -1) {
                latest_valid_suffix = i;
            }
        }
    }
    if (earliest_valid_prefix < latest_valid_suffix || valid_prefixes >= 2 || valid_suffixes >= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}