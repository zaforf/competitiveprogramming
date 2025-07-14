#include <bits/stdc++.h>
using namespace std;

int cnt(const vector<int>& a, int m, int k) {
    int groups = 0, n = a.size();
    vector<bool> seen(n + 2, 0);
    int mex = 0 ;
    for (int i=0;i<n;i++) {
        seen[min(a[i], n+1)] = true;
        while (seen[mex])
            mex++;
        if (mex >= m) {
            groups++;
            mex = 0;
            for (int j=0;j<=min(m+1, n+1);j++)
                seen[j] = 0;
        }
    }
    return groups >= k;
}

void solve() {
    int n, k; cin>>n>>k;
    vector<int> a(n);
    for (int& i : a) cin>>i;
    int l = 0, r = n, ans = 0;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (cnt(a, m, k)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}