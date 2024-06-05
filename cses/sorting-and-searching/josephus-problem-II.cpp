#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    int N=1;
    using T = int;
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return a+b; }
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
    // find i where op(segtree[0:i]) = val
    int search(T val) {
    	int i=1,s=0;
    	while (i<N) {
    		if (s+tree[2*i]<val) {
    			s+=tree[2*i];
    			i=2*i+1;
    		} else
    			i=2*i;
    	}
    	return i-N;
    }
};

int main() {
	int n,k;cin>>n>>k;
	Segtree st(n);
	for (int i=0;i<n;i++) st.upd(i,1);
	int target=k%n;
	for (int i=1;i<=n;i++) {
		int x = st.search(target+1);
		st.upd(x,0);
		cout << x+1 << " ";
		if (i!=n) target = (target+k)%(n-i);
	}
	cout << endl;
	return 0;
}
