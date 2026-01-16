#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

void solve() {
    int n; cin>>n;
    vector<int> bitcount(31, 0);
    for (int i = 1; i <= n; i++) {
        for (int b = 0; b < 31; b++) {
            if (i & (1 << b)) bitcount[b]++;
        }
    }
    vector<int> current, in, out;
    vector<int> possible, next;
    for (int i=0;i<n-1;i++) current.push_back(i);
    for (int i=1;i<=n;i++) possible.push_back(i);
    for (int b = 0; b < 31; b++) {
        int count = 0;
        in.clear(); out.clear();
        for (auto i : current) {
            int res;
            if (count == bitcount[b]) {
                res = 0;
            } else {
                cout << "? " << i + 1 << " " << (1 << b) << endl;
                cin >> res;
            }
            if (res == 1) {
                count++;
                in.push_back(i);
            } else {
                out.push_back(i);
            }
        }
        bool needs_bit = false;
        if (count == bitcount[b]) {
            current = out;
            needs_bit = false;
        } else {
            current = in;
            needs_bit = true;
        }

        for (auto x : possible) {
            if (needs_bit) {
                if (x & (1 << b)) next.push_back(x);
                else {
                    for (int b=0;b<31;b++) {
                        if (x & (1 << b)) bitcount[b]--;
                    }
                }
            } else {
                if (!(x & (1 << b))) next.push_back(x);
                else {
                    for (int b=0;b<31;b++) {
                        if (x & (1 << b)) bitcount[b]--;
                    }
                }
            }
        }
        possible = next;
        next.clear();
        if (possible.size() == 1) break;


    }
    cout << "! " << possible[0] << endl;


}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}