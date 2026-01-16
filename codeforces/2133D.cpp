#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n; cin>>n;
    vecin(a, n);
    vector<long long> dp(n+1, 0ll);
    for (int i=2;i<=n;i++) {
        // take one dmg
        dp[i] = dp[i-1] + 1;
        // take i dmg
        dp[i] = max(dp[i], dp[i-2] + min(i-1, a[i-1]));
    }
    cout << accumulate(a.begin(), a.end(), 0ll) - dp[n] << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}