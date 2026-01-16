#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a;
    for (int i=0;i<k;i++) {
        int ci; cin >> ci;
        a.push_back(n-ci);
    }
    sort(a.begin(), a.end());
    int ans = 1;
    int left = n - a.back() - 1;
    for (int i=0;i<k-1;i++) {
        if (a[i] == 0) continue;
        if (left >= a[i]+1) {
            ans++;
            left -= a[i]+1;
        } else break;
    }
    cout << ans << endl;
    return 0;
}