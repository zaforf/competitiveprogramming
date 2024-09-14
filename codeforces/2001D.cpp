#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+1;

struct Maxtree {
    int N=1;
    using T = int;
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return max(a,b); }
    Maxtree(int n) {
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

struct Mintree {
    int N=1;
    using T = int;
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return min(a,b); }
    Mintree(int n) {
        while (N < n) N <<= 1;
        tree.assign(N<<1, MAXN);
    }
    // update value at position i to val, 0-index
    void upd(int i, T val) {
        i += N;
        tree[i] = val;
        for (i /= 2; i > 0; i /= 2)
            tree[i] = op(tree[2 * i], tree[2 * i + 1]);
    }
    T qry(int l, int r) {
        T res= MAXN; // DON'T FORGET TO CHANGE THIS
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

Maxtree mx(MAXN);
Mintree mn(MAXN);

void solve() {
    int n; cin>>n;
    int a[n]; for (int& i : a) cin>>i;
    vector<vector<int>> indices(n+1);
    set<int> last;
    for (int i=0;i<n;i++) {
        indices[a[i]].push_back(i); 
        mx.upd(i,a[i]);
        mn.upd(i,a[i]);
    }
    int uniq = 0;
    for (int i=1;i<=n;i++)
        if (indices[i].size()) {
            last.insert(indices[i].back());
            uniq++;
        }
    vector<int> ans; int x = 0;
    for (int i=0;i<uniq;i++) {
        int r = *last.begin(), best;
        if (i%2==0)
            best = mx.qry(x,r);
        else
            best = mn.qry(x,r);
        ans.push_back(best);
        int ind = -1;
        for (int erase : indices[best]) {
            if (ind==-1 && x<=erase && erase<=r) ind = erase;
            mx.upd(erase,0);
            mn.upd(erase,MAXN);
        }
        last.erase(indices[best].back());
        x = ind+1;
    }
    cout << uniq << '\n';
    for (int i : ans) cout << i << " ";
    cout << '\n';
    for (auto v : indices)
        for (int i : v) {
            mx.upd(i,0);
            mn.upd(i,MAXN);
        }
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}