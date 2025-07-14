#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin>>n>>q;
    vector<int> a(n);
    vector<int> ind(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }
    for (int i=0;i<q;i++) {
        int l, r, k; cin >> l >> r >> k;
        l--; r--;
        if (l > r || ind[k] < l || ind[k] > r) {
            cout << "-1 ";
            continue;
        }
        int less = k - 1, greater = n - k;
        int want_less = 0, want_greater = 0;
        int m = (l + r) / 2, ans = 0;
        while (a[m] != k) {
            if (m < ind[k]) l = m + 1;
            else r = m - 1;
            bool curr_less = a[m] < k;
            bool less_needed = ind[k] > m;
            m = (l + r) / 2;
            if (curr_less == less_needed) {
                if (curr_less) less--;
                else greater--;
                continue;
            }
            if (less_needed) want_less++;
            else want_greater++;
        }
        if (want_less > less || want_greater > greater) {
            cout << "-1 ";
            continue;
        }
        cout << 2*max(want_less, want_greater)<< " ";
    }
    cout << endl;

}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}