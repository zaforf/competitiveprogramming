#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Segtree {
    int N=1;
    using T = int;
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return (a+b) % MOD; }
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
        T res=0; // DON'T FORGET TO CHANGE THIS
        l += N; r += N;
        while (l <= r) {
            if (l % 2 == 1) res = op(res, tree[l++]);
            if (r % 2 == 0) res = op(res, tree[r--]);
            l /= 2; r /= 2;
        }
        return res;
    }
    // find i where op(segtree[0:i]) = val
    int search(T val) {
        int i=1,s=0;
        while (i<N) {
            if (op(s,tree[2*i])<val) {
                s=op(s,tree[2*i]);
                i=2*i+1;
            } else
                i=2*i;
        }
        return i-N;
    }
};

int main() {
	int n; cin >> n;
	vector<int> a(n), sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int sz = sorted.size();
    Segtree seg(sz);
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();
        int best = seg.qry(0, idx);
        seg.upd(idx, best + 1);
    }
    cout << seg.qry(0, sz - 1) << endl;
	return 0;
}