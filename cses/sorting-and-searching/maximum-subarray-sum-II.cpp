#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Segtree {
    int N=1;
    using T = int;
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return min(a,b); }
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
        T res=1e18; // change based on operator
        l += N; r += N;
        while (l <= r) {
            if (l % 2 == 1) res = op(res, tree[l++]);
            if (r % 2 == 0) res = op(res, tree[r--]);
            l /= 2; r /= 2;
        }
        return res;
    }
};

int32_t main() {
	int n,a,b;cin>>n>>a>>b;
	int v[n]; Segtree st(n);
	for (int &i : v) cin>>i;
	int ans=-1e18,sum=0,mini=0;
	for (int i=0;i<n;i++) { 
		sum += v[i];
		st.upd(i,sum);
		if (i==a-1) ans=max(ans,sum);
		if (i>=a) {
			mini = st.qry(max(i-b,0ll),i-a);
			if (b-1>=i) mini=min(mini,0ll);
			ans = max(ans,sum-mini);
		}
	}
	cout << ans;
	return 0;
}