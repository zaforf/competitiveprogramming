#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;
#define int long long

struct Segtree {
    int N=1;
    using T = int;
    T def = -1;
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return max(a,b); }
    Segtree(int n) {
        while (N < n) N <<= 1;
        tree.assign(N<<1, def);
    }
    // update value at position i to val, 0-index
    void upd(int i, T val) {
        i += N;
        tree[i] = val;
        for (i /= 2; i > 0; i /= 2)
            tree[i] = op(tree[2 * i], tree[2 * i + 1]);
    }
    T qry(int l, int r) {
        T res = def;
        l += N; r += N;
        while (l <= r) {
            if (l % 2 == 1) res = op(res, tree[l++]);
            if (r % 2 == 0) res = op(res, tree[r--]);
            l /= 2; r /= 2;
        }
        return res;
    }
};

void solve() {
    int n; cin>>n;
    vecin(a, n);
    vecin(b, n);
    Segtree seg(2*n+5);
    int ans = 0;
    for (int i=0;i<n;i++) {
        int mx = max(a[i],b[i]);
        if (a[i] == b[i]) {
            ans += (i + 1) * (n - i);
            seg.upd(a[i], i);
            continue;
        }
        // find latest index with a[j] >= mx
        int ind = seg.qry(mx, 2*n+2);
        if (ind >= 0) {
            ans += (ind+1) * (n - i);
        }
        seg.upd(a[i], i);
    }
    cout << ans << endl;


    
}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}