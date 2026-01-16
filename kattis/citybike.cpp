#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n, d, c; cin >> n >> d >> c;
    vecin(a, n);
    auto check = [&](vector<int>& a, int lb, int ub) {
        int min_t = 0, max_t = c;
        for (int i=0;i<n;i++) {
            int del1 = a[i] - lb;
            int del2 = a[i] - ub;
            min_t = min(min_t + del1, min_t + del2);
            max_t = max(max_t + del1, max_t + del2);
            if (max_t < 0) return false;
            if (min_t > c) return false;
            min_t = max(min_t, 0);
            max_t = min(max_t, c);
        }
        return true;
    };
    
    int l1 = 0, r1 = d;
    int ans = 1e9;
    while (l1 <= r1) {
        int m1 = (l1 + r1) / 2;
        int l2 = m1, r2 = d;
        bool found = false;
        while (l2 <= r2) {
            int m2 = (l2 + r2) / 2;
            if (check(a, m1, m2)) {
                ans = min(ans, m2-m1);
                found = true;
                r2 = m2-1;
            } else {
                l2 = m2+1;
            }
        }
        if (found) l1 = m1+1;
        else r1 = m1-1;       
    }
    cout << ans << endl;
    
    return 0;
}