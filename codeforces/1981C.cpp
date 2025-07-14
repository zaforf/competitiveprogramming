#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int last = -1, lasti = -1;
    for (int i=0;i<n;i++) {
        if (i && a[i]>=0 && a[i-1]>=0) {
            if ((a[i] != (a[i-1]/2)) && (a[i-1]!=a[i]/2)) {
                cout << -1 << endl;
                return;
            }
        }


        if (a[i] >= 0) {
            if (lasti >= 0 && lasti < i-1) {
                int min_dist = 0;
                int x = last, y = a[i];
                if (y < x) swap(y,x); // ensure y >= x
                int leading_diff = __builtin_clz(x) - __builtin_clz(y);
                // cout << leading_diff << " " << y << " " << x << endl;
                while ((y >> leading_diff) != x) {
                    x >>= 1;
                    leading_diff++;
                    min_dist++;
                }
                min_dist += leading_diff;
                // cout << "min_dist: " << min_dist << endl;
                if (min_dist > i - lasti || (min_dist % 2 != (i - lasti) % 2)) {
                    cout << -1 << endl;
                    return;
                }
                int d = 0, s = 0;
                if (y == last) {
                    d = -1;
                    s = i;
                } else {
                    d = 1;
                    s = lasti;
                }
                int curr = a[s];
                bool reached_min = false;
                for (int j = 0; j < min_dist; j++) {
                    reached_min = reached_min || (curr == x);
                    if (reached_min) {
                        int diff = __builtin_clz(curr) - __builtin_clz(y);
                        curr *= 2;
                        if ((y >> (diff-1)) & 1)
                            curr++;
                    } else {
                        curr /= 2;
                    }
                    a[s+d] = curr;
                    s += d;
                }
                for (int j = 0; j < (i - lasti) - min_dist; j++) {
                    if (j & 1) curr /= 2;
                    else curr *= 2;
                    a[s+d] = curr;
                    s += d;
                }
            } else if (lasti == -1) {
                int curr = a[i], s = i-1;
                for (int j=0; j < i; j++) {
                    if (j & 1) curr /= 2;
                    else curr *= 2;
                    a[s] = curr;
                    s--;
                }
            }
            last = a[i];
            lasti = i;
        }
    }
    if (lasti != n-1) {
        if (lasti == -1) {
            for (int i = 0; i < n; i++) {
                a[i] = 1 + (i&1);
            }
        } else {
            int curr = a[lasti], s = lasti+1;
            for (int j = 0; j < n - lasti - 1; j++) {
                if (j & 1) curr /= 2;
                else curr *= 2;
                a[s] = curr;
                s++;
            }
        }
    }
    for (int v : a)
        cout << v << " ";
    cout << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}