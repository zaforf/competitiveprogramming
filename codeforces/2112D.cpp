#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i=0;i<n-1;i++) {
        int a, b;
        cin>>a>>b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    bool found = false;
    function<void(int, int, int)> dfs = [&](int node, int p, int parent=-1) {
        if (p == 0) { // special guy
            cout << adj[node][0]+1 << " " << node+1 << endl;
            cout << node+1 << " " << adj[node][1]+1 << endl;
            dfs(adj[node][0], 1, node);
            dfs(adj[node][1], 2, node);
        } else {
            for (int nb : adj[node]) {
                if (nb != parent) {
                    if (p & 1) {
                        cout << node+1 << " " << nb+1 << endl;
                    } else {
                        cout << nb+1 << " " << node+1 << endl;
                    }
                    dfs(nb, p + 1, node);
                }
            }

        }
    };

    for (int i=0;i<n;i++)
        if (deg[i]==2) {
            cout << "YES" << endl;
            found = true;
            dfs(i, 0, -1);
            break;
        }
    if (!found)
        cout << "NO" << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}