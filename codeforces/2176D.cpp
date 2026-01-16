#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define endl '\n'
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;
const int MOD = 998244353;

void solve() {
    int n,m; cin>>n>>m;
    vecin(a,n);
    vector<vector<int>> adj(n);
    vector<int> in(n);
    vector<unordered_map<int,int>> dp(n);
    int ans = 0;
    for (int i=0;i<m;i++) {
        int p,q; cin>>p>>q; p--; q--;
        if (a[p] >= a[q]) {
            dp[q][a[p]]++;
            ans = (ans + 1) % MOD;
        } else {
            adj[p].push_back(q);
            in[q]++;
        }
    }
    vector<int> topo;
    queue<int> q;
    for (int i=0;i<n;i++)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int c = q.front(); q.pop();
        topo.push_back(c);
        for (int nb : adj[c]) {
            in[nb]--;
            if (in[nb] == 0)
                q.push(nb);
        }
    }

    for (int node : topo) {
        int from = a[node];
        for (int nb : adj[node]) {
            int to = a[nb];
            dp[nb][from] = (dp[nb][from] + dp[node][to-from] + 1) % MOD;
            ans = (ans + dp[node][to-from] + 1) % MOD;
            // cout << " adding " << dp[node][to-from] << " from " << from << " -> " << to << endl;
        }

    }
    cout << ans << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}