#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int32_t main() {
    int n; cin>>n;
    vecin(a, n);
    int ans = 0;
    vector<int> ming(n, 1e9);
    int g = a[0];
    for (int i=1;i<n;i++) {
        g = gcd(g, a[i]);
        ming[i] = min(ming[i], g);
    }
    g = a[n-1];
    for (int i=n-2;i>=0;i--) {
        g = gcd(g, a[i]);
        ming[i] = min(ming[i], g);
    }
    for (int i=1;i<n-1;i++) {
        ans += ming[i];
    }
    cout << ans + g << endl;
    return 0;
}