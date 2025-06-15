#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin>>n;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int res = 0;
    // compute original value
    for (int i=0;i<n;i++)
        res += a[i].first - a[0].first + 1;
    vector<int> ans(n);
    ans[a[0].second] = res;
    for (int i = 1; i < n; i++) {
        int diff = a[i].first - a[i-1].first;
        res += diff * (i) - (n - i) * diff;
        ans[a[i].second] = res;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}