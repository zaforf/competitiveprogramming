#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    int N=1;
    using T = int;
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return gcd(a,b); }
    Segtree(int n) {
        while (N < n) N <<= 1;
        tree.assign(N<<1, 0);
    }
    // update value at position i to val, 0-index
    void upd(int i, T val) {
        i += N;
        tree[i] = val;
        for (i /= 2; i > 0; i /= 2)
            tree[i] = op(tree[2 * i], tree[2 * i + 1]);
    }
    T qry(int l, int r) {
        T res=0;
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
    int n,q; cin>>n>>q;
    Segtree st(n-1);
    int last,inp;
    cin >> last;
    for (int i=0;i<n-1;i++) {
        cin >> inp;
        st.upd(i,abs(inp-last));
        swap(inp,last);
    }
    for (int i=0;i<q;i++) {
        int a,b; cin>>a>>b;
        cout << st.qry(a-1,b-2) << (i<q-1 ? " " : "\n");
    }
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}