#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(n+1);
    vector<int> ind(n+1);
    vector<int> bef(n+1), aft(n+1);
    int drops = 0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        ind[a[i]] = i;
        if (i && a[i] < a[i-1])
            drops++;
    }
    for (int i = 1; i <= n; i++) {
        bef[i] = i - 1;
        aft[i] = (i + 1) % (n+1);
    }
    int ans = 0;
    int l = 1, r = n;

    while (drops>0) {
        // remove l linked list style, and update drops
        int i = ind[l];
        int left = bef[i];
        int right = aft[i];

        if (left && a[left] > a[i]) drops--;
        if (right && a[i] > a[right]) drops--;
        if (left && right && a[left] > a[right]) drops++;

        aft[left] = right;
        bef[right] = left;

        i = ind[r];
        left = bef[i];
        right = aft[i];
        if (left && a[left] > a[i]) drops--;
        if (right && a[i] > a[right]) drops--;
        if (left && right && a[left] > a[right]) drops++;

        aft[left] = right;
        bef[right] = left;
        ans++;
        l++, r--;
    }
    cout << ans << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}