#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n,k; cin>>n>>k;
    vector<int> cnt(4*n+5);
    vecin(a,n);
    sort(a.begin(), a.end());
    for (int i=0;i<n;i++) {
        cnt[a[i]]++;
    }
    // prefix it
    for (int i=1;i<=4*n+4;i++) {
        cnt[i] += cnt[i-1];
    }
    int ans = 1;
    for (int i=2;i<=n;i++) {
        int min = i + (i + 1) + 2*i;
        int cnt_less_min = cnt[min - 1];
        for (int j=i;j<=min;j+=i) {
            cnt_less_min -= cnt[j] - cnt[j - 1];
        }
        if (cnt_less_min <= k) {
            ans = i;
        }
    }
    cout << ans << endl;

}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}