#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n, q; cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 3; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> comp(n + 1, -1);
    vector<int> diam(3);
    vector<int> maxdist(n + 1);
    auto dfs = [&](auto&& self, int u, int c, bool set) -> pair<int, int> {
        comp[u] = c;
        pair<int, int> farthest = {0, u};
        for (int v : adj[u]) {
            if (comp[v] == -1) {
                auto [dist, node] = self(self, v, c, set);
                dist++;
                farthest = max(farthest, {dist, node});
            }
        }
        if (!set) comp[u] = -1;
        return farthest;
    };

    auto set_depth = [&](auto&& self, int u, int p, int d) -> void {
        maxdist[u] = max(maxdist[u], d);
        for (int v : adj[u]) {
            if (v != p) {
                self(self, v, u, d + 1);
            }
        }
    };

    int comps = 0;
    for (int i = 1; i <= n; i++) {
        if (comp[i] == -1) {
            auto [_, node] = dfs(dfs, i, comps, false);
            auto [dist1, other] = dfs(dfs, node, comps, true);
            set_depth(set_depth, node, -1, 0);
            set_depth(set_depth, other, -1, 0);
            diam[comps] = maxdist[other];
            comps++;
        }
    }
    for (int i=0;i<q;i++) { 
        int a, b; cin >> a >> b;
        int neither = 3 ^ comp[a] ^ comp[b];
        cout << maxdist[a]+1 + diam[neither]+1 + maxdist[b]+1 << endl;
    }
    return 0;
}