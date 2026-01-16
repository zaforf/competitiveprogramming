#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n,q; cin>>n>>q;
    vecin(a, n);
    vector<int> prefix(n+1, 0);
    vector<int> cnt1(n+1, 0);

    for (int i=0;i<n-1;i++) {
        if (a[i] == a[i+1]) {
            prefix[i+1] = prefix[i] + 1;
        } else {
            prefix[i+1] = prefix[i];
        }
        if (a[i] == 1) {
            cnt1[i+1] = cnt1[i] + 1;
        } else {
            cnt1[i+1] = cnt1[i];
        }
    }
    prefix[n] = prefix[n-1];
    cnt1[n] = cnt1[n-1] + (a[n-1] == 1 ? 1 : 0);

    while (q --> 0) {
        int l, r; cin>>l>>r;
        l--;
        int pair = prefix[r-1] - prefix[l];
        int ones = cnt1[r] - cnt1[l];
        int len = r - l;
        if (len % 3 != 0 || ones % 3 != 0) {
            cout << -1 << endl;
        } else {
            if (pair)
                cout << len / 3 << endl;
            else
                cout << (len-3) / 3 + 2 << endl;
        }        
    }
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}