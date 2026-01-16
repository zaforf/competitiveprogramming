#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n, k; cin >> n >> k;
    vecin(a, n);
    sort(a.begin(), a.end(), greater<int>());
    multiset<int> open;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (open.size() == 0 || k < a[i]+*open.begin()) {
            open.insert(a[i]);
        } else {
            ans++;
            open.erase(open.begin());
        }
    }
    cout << ans + open.size() << endl;


    return 0;
}