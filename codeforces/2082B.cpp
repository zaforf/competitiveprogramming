#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int a,n,m; cin>>a>>n>>m;
    int x = a;
    int last_i = -1;
    for (int i=0;i<min(32,n+m);i++) {
        if (x & 1) last_i = i;
        x >>= 1;
    }
    bool add_one = false;
    if (last_i != -1 && m >= n + m - last_i) {
        add_one = true;
    } 
    int p = 0;
    if (n + m <= 32) {
        if (n + m != 0) {
            int v = 1 << (n + m - 1);
            while (v & a) {
                v >>= 1;
                p++;
            }
            if (v > 0 && (v - 1) & a) {
                p++;
            }
        }
    } else {
        if (a) p++;
    }


    cout << x + ((n >= p) ? 0 : 1) << " " << x + (add_one ? 1 : 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}