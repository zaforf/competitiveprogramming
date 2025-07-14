#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,k; cin>>n>>m>>k;
    int div = n / (m+1);
    int printed = 0;
    while (printed < n) {
        for (int i = 0; i < max(k,div) && printed < n; ++i) {
            cout << i << " ";
            printed++;
        }
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