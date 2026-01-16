#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int l,r; cin>>l>>r; // l = 0

    if (r == 0) {
        cout << 0 << endl;
        cout << 0 << endl;
        return;
    }
    vector<int> ans(r+1, -1);
    for (int i=r; i>=l; i--) {
        if (ans[i] != -1) continue;
        if (i == 0) {
            ans[0] = 0;
            continue;
        }
        int highest_bit = 31 - __builtin_clz(i);
        int opp = i ^ ((1 << (highest_bit + 1)) - 1);
        ans[opp] = i;
        ans[i] = opp;
    }
    long long score = 0;
    for (int i=l; i<=r; i++)
        score += i | ans[i];
    cout << score << endl;
    for (int i=l; i<=r; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}