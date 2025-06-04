#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,a,b; cin>>n>>a>>b;
    if (a+b>n || (!!a ^ !!b)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> c(n);
    for (int i=0;i<n;i++) c[i] = i;
    bool swp = false;
    if (b > a) {
        swp = true;
        int t = a;
        a = b;
        b = t;
    }
    int i;
    for (i=n-1;i>=0 && b>1;i-=2) {
        swap(c[i], c[i-1]);
        b--;
        a--;
    }
    while (i>=a+b) i--;
    for (;i>0;i--) {
        swap(c[i], c[i-1]);
    }
    if (swp) {
        for (int i : c) cout << i+1 << " ";
        cout << endl;
        for (int i=0;i<n;i++) cout << i+1 << " ";
        cout << endl;
    } else {
        for (int i=0;i<n;i++) cout << i+1 << " ";
        cout << endl;
        for (int i : c) cout << i+1 << " ";
        cout << endl;
    }
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}