#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n; cin>>n;
    vecin(a,n);
    vecin(b,n);
    vector<bool> applied(n, false);
    bool good = (a[n-1] == b[n-1]);
    for (int i=n-2;i>=0 && good;i--) {
        if (a[i] == b[i]) {
            continue;
        }
        if (applied[i+1]) {
            if ((a[i] ^ b[i+1]) == b[i]) {
                applied[i] = true;
                continue;
            }
        }
        if ((a[i] ^ a[i+1]) == b[i]) {
            applied[i] = true;
            continue;
        }
        good = false;

    }
    if (good) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}