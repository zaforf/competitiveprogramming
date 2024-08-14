#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e6+1;

struct Segtree {
    int N=1;
    using T = int;
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return max(a,b); }
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
        T res = 0;
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
        if (i==2*N-1) return -1;
        return i-N;
    }
};

Segtree st(MAX);

void solve() {
	int n,m; cin>>n;
	set<int> s; s.insert(0);
	for (int i=0;i<n;i++) {
		int a; cin>>a;
		int l = *prev(s.end());
		s.insert(a);
		st.upd(l,a-l-1);
	}

	auto rem = [&](int lo) {
		st.upd(lo,0);
	};
	auto add = [&](int gap, int lo) {
		st.upd(lo,gap);
	};

	cin>>m;
	for (int i=0;i<m;i++) {
		char o; int k; cin>>o>>k;
		if (o=='+') {
			auto it = s.upper_bound(k);
			int lo = *prev(it), hi = *it;
			add(k-lo-1,lo);
			add(hi-k-1,k);
			s.insert(k);
		} else if (o=='-') {
			auto it = s.find(k);
			int lo = *prev(it);
			rem(lo);
			if (next(it)!=s.end()) {
				int hi = *next(it);
				rem(k);
				add(hi-lo-1,lo);
			}
			s.erase(k);
		} else {
			int ret = st.search(k);
			if (ret==-1) cout << *prev(s.end())+1 << ' ';
			else cout << ret+1 << ' ';
		}
	}
	cout << '\n';
	for (int x : s) rem(x);
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}