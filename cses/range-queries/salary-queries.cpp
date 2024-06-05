#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
 
vector<int> indices;
 
int getIndex(int a) {
	return lower_bound(indices.begin(),indices.end(),a)-indices.begin();
}
 
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
	int n,q;cin>>n>>q;
	int v[n];
	pair<int,pii> queries[q];
	for (int i=0;i<n;i++) {
		cin>>v[i];
		indices.push_back(v[i]);
	}
	for (int i=0;i<q;i++) {
		char c;cin>>c;
		int a,b;cin>>a>>b;
		if (c=='?') indices.push_back(a);
		indices.push_back(b);
		queries[i] = {(c=='?'),{a,b}};
	}
	sort(indices.begin(),indices.end());
	indices.erase(unique(indices.begin(),indices.end()),indices.end());

	Segtree st(indices.size()+1);

	for (int i : v)
		st.upd(getIndex(i),1);

	for (int i=0;i<q;i++) {
		if (queries[i].f)
			cout << st.qry(getIndex(queries[i].s.f),getIndex(queries[i].s.s)) << endl;
		else {
			int curr = v[queries[i].s.f-1];
			v[queries[i].s.f-1] = queries[i].s.s;
			st.upd(getIndex(curr),-1);
			st.upd(getIndex(queries[i].s.s),1);
		}
	}
	return 0;
}