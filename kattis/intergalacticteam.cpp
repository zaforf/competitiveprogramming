#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> adj(n);
    for (int i=0;i<m;i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
    }
    vector<bool> vis(n);
    auto dfs = [&](auto&& self, int u) -> int {
        vis[u] = true;
        int n_edges = 0;
        for (int v : adj[u]) {
            if (!vis[v]) n_edges += self(self, v);
            n_edges++;
        }
        return n_edges;
    };
    int ans = 0;
    for (int i=0;i<n;i++) {
        if (!vis[i]) {
            int n_edges = dfs(dfs, i);
            if (n_edges == k * (k - 1)) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}