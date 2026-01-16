#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _+1 << " "; cout << endl;

void solve() {
    int n; cin>>n;
    vector<vector<int>> adj(n);
    for (int i=0;i<n-1;i++) {
        int u,v; cin>>u>>v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> path; // stores path from 0 to n-1
    vector<int> edge_cnt(n, 0);
    auto dfs = [&](auto&& self, int u, int p) -> bool {
        path.push_back(u);
        if (u == n-1) return true;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (self(self, v, u)) return true;
        }
        path.pop_back();
        return false;
    };
    dfs(dfs, 0, -1);
    // increment edge_cnt for node in path so they don't get removed
    for (int u : path)
        edge_cnt[u]++;
    vector<int> white, black; // queues for white and black nodes (alternating levels)
    auto dfs2 = [&](auto&& self, int u, int p, int color) -> void {
        edge_cnt[u]++;
        for (int v : adj[u]) {
            if (v == p) continue;
            self(self, v, u, 1 - color);
            edge_cnt[u]++;
        }
        if (edge_cnt[u] == 1) { // leaf node
            if (color == 0) white.push_back(u);
            else black.push_back(u);
        }
    };
    dfs2(dfs2, 0, -1, 0);
    int color = 1;
    // start loop: if color == 0, remove white node, remove edges, add new leaves to black
    // else remove black node, remove edges, add new leaves to white
    // stop when both queues are empty
    vector<string> output;
    while (!white.empty() || !black.empty()) {
        if (color == 0 && !white.empty()) {
            int u = white.back(); white.pop_back();
            output.push_back("2 " + to_string(u+1));
            for (int v : adj[u]) {
                edge_cnt[v]--;
                if (edge_cnt[v] == 1) { // new leaf
                    black.push_back(v);
                }
            }
        } else if (color == 1 && !black.empty()) {
            int u = black.back(); black.pop_back();
            output.push_back("2 " + to_string(u+1));
            for (int v : adj[u]) {
                edge_cnt[v]--;
                if (edge_cnt[v] == 1) { // new leaf
                    white.push_back(v);
                }
            }
        }
        color = 1 - color;
        output.push_back("1");
    }


    // do similar process on nodes in path
    // [0] = black, [1] = white, etc
    if (color == 1) {
        color = 0;
        output.push_back("1");
    }
    for (int i=0;i<int(path.size())-1;i++) {
        output.push_back("2 " + to_string(path[i]+1));
        output.push_back("1");
    }
    cout << output.size() << endl;
    for (auto &s : output) {
        cout << s << endl;
    }

}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}