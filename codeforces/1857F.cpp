#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    map<int,int> cnt;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    int q; cin>>q;
    for (int i=0;i<q;i++) {
        int b,c; cin>>b>>c;
        int det = b*b - 4ll*c;
        if (det < 0) {
            cout << "0 ";
            continue;
        } else if (det == 0) {
            cout << 1ll*cnt[b/2]*(cnt[b/2]-1)/2 << " ";
            continue;
        } else {
            int d = sqrt(det);
            if (d*d != det) {
                cout << "0 ";
                continue;
            }
            int x1 = (b + d) / 2;
            int x2 = (b - d) / 2;
            if (x1 + x2 != b || x1 * x2 != c) {
                cout << "0 ";
                continue;
            }
            // cout << x1 << " " << x2 << endl;
            cout << 1ll*cnt[x1] * cnt[x2] << " ";
        }
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