#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Segtree {
    int N=1;
    using T = int;
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return max(a, b); }
    Segtree(int n) {
        while (N < n) N <<= 1;
        tree.assign(N<<1, 0);
    }
    // update value at position i to val
    void upd(int i, T val) {
        i += N;
        tree[i] += val;
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
    int n,m; cin>>n>>m;
    Segtree st(n);
    for (int i = 0; i < n; ++i) {
        int inp; cin >> inp; st.upd(i,inp);
    }
    for (int i = 0; i < m; ++i) {
        int x; cin>>x;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (st.qry(0, mid) >= x) r = mid;
            else l = mid + 1;
        }
        if (r == n) {
            printf("%d%c", 0, i == m - 1 ? '\n' : ' ');
        } else {
            printf("%d%c", l + 1, i == m - 1 ? '\n' : ' ');
            st.upd(l, -x);
        }
    }
    return 0;
}
