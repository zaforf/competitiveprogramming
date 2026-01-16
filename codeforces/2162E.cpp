#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n,k; cin>>n>>k;
    vecin(a, n);
    vector<int> cnt(n+1, 0);
    vector<int> b;
    for (int i=n-1;i>=0;i--) {
        int v = a[i];
        if (cnt[v] == 0)
            b.push_back(v);
        cnt[v]++;
    }
    reverse(b.begin(), b.end());
    vector<int> missing;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0)
            missing.push_back(i);
    }
    int m = missing.size();
    for (int i=0;i<min(k,m);i++) {
        cout << missing[i] << " ";
    }
    k -= min(k, m);
    for (int i=0;i<k;i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}