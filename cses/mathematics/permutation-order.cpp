#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;

using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long
int fac[21];
ordered_set<int> os;

void find_perm(int n, int k, ordered_set<int>& os) {
    if (n == 0) return;
    int f = fac[n - 1];
    int idx = (k - 1) / f;
    cout << *os.find_by_order(idx) << " ";
    os.erase(os.find_by_order(idx));
    find_perm(n - 1, k - idx * f, os);
}


void solve() {
    int c,n,k=1; cin>>c>>n;
    os.clear();
    for (int i = 1; i <= n; i++) os.insert(i);
    if (c==1) {
        cin >> k;
        find_perm(n, k, os);
    } else {
        vector<int> perm(n);
        for (int& i : perm) cin >> i;
        for (int i=1; i <= n; i++) {
            int idx = os.order_of_key(perm[i-1]);
            k += idx * fac[n - i];
            os.erase(perm[i-1]);
        }
        cout << k;
    }
    
    cout << endl;
}

int32_t main() {
    fac[0] = 1;
    for (int i = 1; i <= 20; i++) fac[i] = fac[i - 1] * i;
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}