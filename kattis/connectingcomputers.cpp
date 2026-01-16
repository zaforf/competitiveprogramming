#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n, m, k; cin >> n >> m >> k;
    unordered_map<string,int> ts; int t = 0;
    for (int i=0;i<k;i++) {
        string s; cin >> s;
        ts[s] = t++;
    }
    vector<vector<array<int,2>>> adj(n);
    array<int,25> tot{};
    for (int i=0;i<m;i++) {
        int a, b; string t; cin >> a >> b >> t; a--; b--;
        adj[a].push_back({b, ts[t]});
        adj[b].push_back({a, ts[t]});
        tot[ts[t]]++;
    }
    vector<int> vis(n);
    vector<array<int,25>> seen(n, array<int,25>{});
    array<int,25> cnt{};
    vector<vector<int>> bad(25, vector<int>(25));
    int required = 0;
    auto dfs = [&](auto self, int v, int p) -> void {
        vis[v] = 1;
        seen[v] = cnt;
        bool has_back_edge = false;

        for (auto [u, c] : adj[v]) {
            if (u == p) continue;
            if (vis[u] == 2) continue; // already considered back edge

            cnt[c]++;
            if (!vis[u]) {
                self(self, u, v);
            } else {
                vector<int> cycle;
                for (int i=0;i<k;i++) {
                    if (cnt[i] - seen[u][i] == 1) {
                        cycle.push_back(i);
                    } else if (cnt[i] - seen[u][i] > 1) {
                        // this type is required
                        required |= (1 << i);
                    }
                    tot[i] -= (cnt[i] - seen[u][i]);
                }
                // for all pairs, mark as bad
                for (int i=0;i<cycle.size();i++) {
                    for (int j=i+1;j<cycle.size();j++) {
                        bad[cycle[i]][cycle[j]] = 1;
                        bad[cycle[j]][cycle[i]] = 1;
                    }
                }
                has_back_edge = true;
            }
            cnt[c]--;
        }
        if (has_back_edge)
            vis[v] = 2;
    };
    dfs(dfs, 0, -1);
    for (int i=0;i<k;i++) {
        if (tot[i] > 0) {
            required |= (1 << i);
        }
    }
    int min_c = 1e9, ans = 0;

    uint32_t conflict[25] = {};
    for (int i=0;i<k;i++)
      for (int j=0;j<k;j++)
        if (bad[i][j]) conflict[i] |= (1u<<j);


    for (int mask=0; mask < (1<<k); mask++) {
        if ((mask & required) != required) continue; // prune early

        bool ok = true;
        uint32_t inv = ((1u<<k)-1) ^ mask;
        for (int j=0;j<k;j++) if (inv & (1u<<j))
            if (conflict[j] & inv) { ok = false; break; }

        if (ok) {
            min_c = min(min_c, __builtin_popcount(mask));
            ans++;
        }
    }
    cout << min_c << endl << ans << endl;


    return 0;
}