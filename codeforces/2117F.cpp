#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int binexp(int a, int b) {
    int ret=1;
    while (b) {
        if (b&1) {
            ret *= a;
            ret %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ret;
}

void solve() {
    int n; cin>>n;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    vector<int> leafs;
    for (int i = 1; i < n; i++)
        if (deg[i] == 1)
            leafs.push_back(i);
    if (leafs.size() > 2) {
        cout << "0\n";
        return;
    }
    if (leafs.size() == 1) {
        cout << binexp(2, n) << endl;
        return;
    }
    int a = 0, b = 0;
    int p = leafs[0], q = leafs[1];
    vector<bool> vis(n);
    while (deg[p] < 3 && p != 0) {
        vis[p] = true;
        a++;
        if (deg[p] == 1)
            p = adj[p][0];
        else if (deg[p] == 2)
            p = vis[adj[p][0]] ? adj[p][1] : adj[p][0];
    }
    while (deg[q] < 3 && q != 0) {
        b++;
        vis[q] = true;
        if (deg[q] == 1)
            q = adj[q][0];
        else if (deg[q] == 2)
            q = vis[adj[q][0]] ? adj[q][1] : adj[q][0];
    }
    int m = min(a,b);
    cout << (binexp(2, n - 2*min(a, b) - (a>m)) +  binexp(2, n - 2*m - (b>m))) % MOD << endl;
}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}