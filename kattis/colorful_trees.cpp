#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << endl; cout << endl;

int main() {
    int n; cin >> n;
    vecin(c, n);
    unordered_map<int,int> cnt;
    for (auto x : c) cnt[x]++;
    vector<long long> ans(n-1);
    vector<vector<array<int, 2>>> edges(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        edges[u].push_back({v, i});
        edges[v].push_back({u, i});
    }
    auto dfs = [&](auto self, int u, int p, int idx) -> unordered_map<int,int> {
        unordered_map<int,int> cur;
        cur[c[u]]++;
        for (auto [v, idx] : edges[u]) {
            if (v == p) continue;
            auto child = self(self, v, u, idx);
            if (child.size() > cur.size()) swap(child, cur);
            for (auto [col, num] : child) {
                cur[col] += num;
            }
        }
        if (idx != -1)
            for (auto [col, num] : cur) {
                ans[idx] += (cnt[col] - num + 0ll) * num;
            }
        return cur;
    };
    dfs(dfs, 0, -1, -1);
    vecout(ans);


    return 0;
}