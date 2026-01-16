#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n; cin>>n;
    vecin(a, 2*n);
    vector<int> ans(n,0);
    for (int i=0;i<2*n-1;i++) {
        int to_edge = min(i, 2*n-2 - i);
        ans[to_edge] += a[i+1] - a[i];
    }
    for (int i=n-3;i>=0;i--) {
        ans[i] += ans[i+2];
    }
    int sofar = 0;
    for (int i=0;i<n-1;i++) {
        int inc = a[2*n-1-i] - a[i];
        sofar += inc;
        ans[i+1] += sofar;
    }
    vecout(ans);
}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}