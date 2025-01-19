#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Segtree {
    int N=1;
    using T = long long;
    vector<T> tree;
    T op(T a, T b) { return a+b; }
    Segtree(int n) {
        while (N < n) N <<= 1;
        tree.assign(N<<1, 0);
    }
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

int main() {
    int n; cin >> n;
    Segtree st(n);
    vector<pair<int,int>> pre(n);
    for (int i=0;i<n;i++) {
        cin >> pre[i].first;
        pre[i].second = i;
    }
    sort(pre.begin(), pre.end());
    vector<int> a(n);
    vector<int> more(n);
    for (int i=0;i<n;i++) a[pre[i].second] = i;

    ordered_set<int> s; int sz = 0;
    for (int i=0;i<n;i++) {
        more[i] = sz - s.order_of_key(a[i]);
        s.insert(a[i]); sz++;
    }

    long long ans = 0;
    for (int i=0;i<n;i++) {
        ans += st.qry(a[i]+1,n-1);
        st.upd(a[i], more[i]);
    }
    cout << ans;
    return 0;
}