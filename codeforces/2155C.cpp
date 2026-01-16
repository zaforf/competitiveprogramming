#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n; cin>>n;
    vecin(a, n);
    vector<int> b(n);
    b[0] = 1;
    for (int i=1;i<n;i++) {
        if (a[i] == a[i-1])
            b[i] = 3 - b[i-1];
        else {
            if (abs(a[i]-a[i-1]) > 1) {
                cout << 0 << endl;
                return;
            }
            b[i] = b[i-1];
        }
    }
    int o = 0, t = 0;
    vector<int> c(n);
    // c[i] = # of 1 to left plus # of 2 to right
    for (int i=0;i<n;i++) {
        if (b[i] == 1) o++;
    }
    for (int i=n-1;i>=0;i--) {
        if (b[i] == 1) o--;
        c[i] = o + t + 1;
        if (b[i] == 2) t++;
    }
    int ans = 0;
    bool good = true;
    for (int i=0;i<n;i++) {
        if (c[i] != a[i]) {
            good = false;
            break;
        }
    }
    if (good) ans++;
    // try swapping 1 and 2, recalculate c
    o = 0; t = 0;
    for (int i=0;i<n;i++) {
        if (b[i] == 2) o++;
    }

    for (int i=n-1;i>=0;i--) {
        if (b[i] == 2) o--;
        c[i] = o + t + 1;
        if (b[i] == 1) t++;
    }
    
    good = true;
    for (int i=0;i<n;i++) {
        if (c[i] != a[i]) {
            good = false;
            break;
        }
    }
    if (good) ans++;
    cout << ans << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}