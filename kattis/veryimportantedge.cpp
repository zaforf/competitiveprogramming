#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;
#define int long long

const int MAXN = 100001;
vector<int> e(MAXN,-1);

int get(int x) { return (e[x]<0 ? x : e[x]=get(e[x])); }

bool merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a==b) return false;
    if (e[a]>e[b]) swap(a,b);
    e[a] += e[b];
    e[b] = a;
    return true;
}

int sz(int x) {return -e[get(x)];}

struct Segtree {
    int N=1;
    using T = array<int,2>;
    T def = {1000000, 0}; // default
    vector<T> tree;
    // operator: must be associative and commutative
    T op(T a, T b) { return a[0] < b[0] ? a : b; }
    Segtree(int n) {
        while (N < n) N <<= 1;
        tree.assign(N<<1, def);
    }
    // update value at position i to val, 0-index
    void upd(int i, T val) {
        i += N;
        tree[i] = val;
        for (i /= 2; i > 0; i /= 2)
            tree[i] = op(tree[2 * i], tree[2 * i + 1]);
    }
    T qry(int l, int r) {
        T res = def;
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
    int n, m; cin >> n >> m;
    vector<array<int,3>> edges(m);
    for (int i=0; i<m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges[i] = {w,a-1,b-1};
    }
    sort(edges.begin(), edges.end());
    vector<bool> used;
    vector<vector<array<int,2>>> adj(n);
    int mst = 0;
    for (auto [w,a,b] : edges) {
        if (merge(a,b)) {
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
            used.push_back(true);
            mst += w;
        } else used.push_back(false);
    }
    vector<array<int,2>> par(n);
    vector<int> height(n);
    Segtree st(3*n);
    unordered_map<int,int> first;
    int i = 0;
    function<void(int,int,int,int)> dfs = [&](int u, int p, int w, int d) {
        par[u] = {p,w};
        if (!first.count(u)) first[u] = i;
        height[u] = d;
        st.upd(i++, {d, u});
        for (auto [v,ww] : adj[u]) {
            if (v!=p) {
                dfs(v,u,ww,d+1);
                st.upd(i++, {d, u});
            }
        }
    };
    dfs(0,0,0,0);
    vector<int> skip(n, -1);
    int ans = mst;
    for (int i=0;i<m;i++) {
        if (used[i]) continue;
        auto [w,a,b] = edges[i];
        int u = a, v = b;
        int lca = st.qry(min(first[u],first[v]), max(first[u],first[v]))[1];
        int lca_h = height[lca];
        int min_edge = 1e9;
        // cout << u << " " << v << " " << lca << endl;
        while (height[u] > lca_h) {
            int go = par[u][0];
            if (skip[u] == -1) {
                min_edge = min(min_edge, par[u][1]);
                skip[u] = lca;
            } else {
                go = skip[u];
                if (lca_h < height[go]) {
                    skip[u] = lca;
                }
            }
            u = go;
        }
        while (height[v] > lca_h) {
            int go = par[v][0];
            if (skip[v] == -1) {
                min_edge = min(min_edge, par[v][1]);
                skip[v] = lca;
            } else {
                go = skip[v];
                if (lca_h < height[go]) {
                    skip[v] = lca;
                }
            }
            v = go;
        }
        ans = max(ans, mst - min_edge + w);
    }
    cout << ans << endl;

    return 0;
}