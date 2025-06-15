#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int mn = 0, dp;
    vector<int> consider(n+1, 10000000);
    for (int i=0;i<=n;i++) {
        mn = min(mn, consider[i]);
        dp = min(i, i + mn);
        if (i < n && a[i] + i + 1 < n + 1)
            consider[a[i] + i + 1] = min(consider[a[i] + i + 1], dp - i - a[i] - 1);

    }
    cout << dp << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}