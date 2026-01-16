#include <bits/stdc++.h>
using namespace std;
#define int long long

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;


const int MOD = 998244353;
int exp(int a,int b) {
    int ret = 1;
    a %= MOD;
    while (b) {
        if (b&1) ret = ret * a % MOD;
        a = a * a % MOD;
        b>>=1;
    }
    return ret;
}

void solve() {
    int n, m; cin>>n>>m;
    vector<int> prob(m+1); prob[0] = 1;
    vector<int> all_off(m+1, 1);
    vector<vector<array<int,3>>> starts(m+1);
    for (int i=0;i<n;i++) {
        int l, r, p, q; cin>>l>>r>>p>>q;
        starts[r].push_back({l, p, q});
    }

    for (int i=1;i<=m;i++) {
        all_off[i] = all_off[i-1];
        for (auto &[l, p, q] : starts[i]) {
            all_off[i] = all_off[i] * (q - p) % MOD * exp(q, MOD - 2) % MOD;
        }
    }

    
    for (int i=1;i<=m;i++) {
        for (auto &[l, p, q] : starts[i]) {
            int off_between = all_off[i] * exp(all_off[l-1], MOD - 2) % MOD;
            prob[i] = (prob[i] + prob[l-1] * off_between % MOD * exp(q - p, MOD - 2) % MOD * p % MOD) % MOD;
        }

    }

    cout << prob[m] << endl;
}

int32_t main() {
    // int T;cin>>T;
    // while (T --> 0) {
        solve();
    // }
    return 0;
}