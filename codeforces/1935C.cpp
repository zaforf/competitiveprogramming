#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n,l; cin>>n>>l;
    vector<pair<int,int>> msgs;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        msgs.push_back({y, x});
    }
    vector<int> prefix(n);
    // prefix of pair seconds
    sort(msgs.begin(), msgs.end());
    prefix[0] = msgs[0].second;
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i-1] + msgs[i].second;
    int ans = 0;
    for (int i=0;i<n;i++) {
        cout << msgs[i].first << " " << msgs[i].second << endl;
        for (int j=i;j<n;j++) {
            int pref = prefix[j] - (i ? prefix[i-1] : 0);
            if (msgs[j].first - msgs[i].first + pref <= l)
                ans = max(ans, j-i+1);
        }
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