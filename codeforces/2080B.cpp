#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n,m,k; cin>>n>>m>>k;
    vector<int> a(n), prefix(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i-1] + a[i];

    for (int i = 0; i < m; i++) cin >> b[i], b[i]--;
    int ans = 0;
    int p = 0;
    for (int i=0;i<n;i++) {
        while (p < m && b[p] < i)
            p++;
        if (p == m) break;
        if (prefix[b[p]] - prefix[i] > k) continue;
        ans = max(ans, b[p]-i + (k - (prefix[b[p]] - prefix[i]))/a[i]);
        // cout << i << " " << b[p] << " " << b[p]-i + (k - (prefix[b[p]] - prefix[i]))/a[i] << endl;
    }
    int p2 = 0;
    for (int i = b[0]+1; i < n; i++) {
        while (p2 < m && b[p2] < i)
            p2++;
        p2--;
        if (p2 == m) break;
        if (prefix[i-1] - (b[p2] ? prefix[b[p2]-1] : 0) > k) continue;
        ans = max(ans, i - b[p2] + (k - (prefix[i-1] - (b[p2]?prefix[b[p2]-1]:0)))/a[i]);
        // cout << i << " " << b[p2] << " " << i - b[p2] + (k - (prefix[i-1] - (b[p2]?prefix[b[p2]-1]:0)))/a[i] << endl;
    
    
    }
    

    cout << ans << endl;

    
}

int32_t main() {
    // int T;cin>>T;
    // while (T --> 0) {
        solve();
    // }
    return 0;
}
