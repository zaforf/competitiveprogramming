#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << endl; cout << endl;


struct Segtree {
    int N=1;
    using T = int;
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return min(a,b); }
    Segtree(int n) {
        while (N < n) N <<= 1;
        tree.assign(N<<1, 1e9+1);
    }
    // update value at position i to val, 0-index
    void upd(int i, T val) {
        i += N;
        tree[i] = val;
        for (i /= 2; i > 0; i /= 2)
            tree[i] = op(tree[2 * i], tree[2 * i + 1]);
    }
    T qry(int l, int r) {
        T res=1e9+1; // DON'T FORGET TO CHANGE THIS
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
    int n, q; cin >> n >> q;
    vector<array<int,3>> sps(n);
    unordered_map<int,multiset<int>> spsy;
    vector<int> ys;
    for (int i=0; i<n; i++) {
        cin >> sps[i][0];
    }
    for (int i=0; i<n; i++) {
        cin >> sps[i][1];
        ys.push_back(sps[i][1]);
    }
    for (int i=0; i<n; i++) {
        cin >> sps[i][2];
        spsy[sps[i][1]].insert(sps[i][2]);
    }

    sort(sps.begin(), sps.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    unordered_map<int,int> y2i;
    for (int i=0; i<ys.size(); i++) y2i[ys[i]] = i;
    int len = ys.size();
    vector<array<int,3>> qs;
    vector<int> ans(q);
    for (int i=0; i<q; i++) {
        int l, r; cin >> l >> r;
        qs.push_back({l, r, i});
    }
    sort(qs.begin(), qs.end());
    Segtree seg(len);
    // initialize segment tree
    for (int y : ys) {
        int i = y2i[y];
        seg.upd(i, *spsy[y].begin());
    }
    int p = 0;
    for (int i=0;i<q;i++) {
        int l = qs[i][0], r = qs[i][1], qi = qs[i][2];
        while (p < n && sps[p][0] < l) {
            int y = sps[p][1], c = sps[p][2];
            auto &s = spsy[y];
            s.erase(s.find(c));
            int val = s.empty() ? (1e9+1) : *s.begin();
            seg.upd(y2i[y], val);
            p++;
        }
        int ri = lower_bound(ys.begin(), ys.end(), r) - ys.begin();
        int res = seg.qry(ri, len-1);
        ans[qi] = (res == 1e9+1) ? -1 : res;
    }
    vecout(ans);

    return 0;
}