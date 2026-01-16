#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int solve() {
    int n; cin >> n;
    vector<int> a(2*n);
    unordered_set<int> in; in.insert(1);
    unordered_set<int> other;
    for (int i=2;i<=2*n;i++) {
        cout << "? " << in.size()+1 << " ";
        for (int v : in) cout << v << " ";
        cout << i << endl;

        int res; cin>>res;
        if (res != 0) {
            other.insert(i);
            a[i-1] = res;
        } else {
            in.insert(i);
        }
    }
    for (int i=1;i<=2*n;i++) {
        if (other.contains(i)) {
            continue;
        }
        cout << "? " << other.size()+1 << " ";
        for (int v : other) cout << v << " ";
        cout << i << endl;


        int res; cin>>res;
        a[i-1] = res;
    }
    cout << "! ";
    vecout(a);

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T-- > 0) {
        solve();
    }

    return 0;
}