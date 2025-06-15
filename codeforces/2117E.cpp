#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for (int& i : a) cin>>i;
    for (int& i : b) cin>>i;
    set<int> seen;
    for (int i=n-1;i>=0;i--) {
        if (a[i]==b[i]) {
            cout << i+1 << endl;
            return;
        } else {
            if (seen.contains(a[i]) || seen.contains(b[i])) {
                cout << i+1 << endl;
                return;
            }
            if (i < n-1) {
                if ((b[i]==b[i+1] || a[i]==a[i+1])) {
                    cout << i+1 << endl;
                    return;
                }
                seen.insert(a[i+1]);
                seen.insert(b[i+1]);
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}