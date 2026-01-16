#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin>>n;
    vecin(a, n);
    vector<pair<int,map<int,int>>> dp(n);
    // dp[0].first = 1; dp[0].second[0] = 1;
    for (int i=0;i<n;i++) {
        dp[i].first = 1;
        dp[i].second[0] = 1;
        for (int j=0;j<i;j++) {
            if (a[j] <= a[i]) {
                dp[i].first = (dp[i].first + dp[j].first) % MOD;
                for (auto &[key, val] : dp[j].second) {
                    if (a[j] < key && key <= a[i]) {
                        dp[i].second[a[j]] = (dp[i].second[a[j]] + val) % MOD;
                    } else {
                        dp[i].second[key] = (dp[i].second[key] + val) % MOD;
                    }
                }
            } else {
                for (auto &[key, val] : dp[j].second) {
                    if (key <= a[i]) {
                        dp[i].first = (dp[i].first + val) % MOD;
                        dp[i].second[a[j]] = (dp[i].second[a[j]] + val) % MOD;
                    }
                }
            }
        }
    }
    int ans = 1;
    for (int i=0;i<n;i++) {
        ans = (ans + dp[i].first) % MOD;
    }
    cout << ans << endl;

}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}