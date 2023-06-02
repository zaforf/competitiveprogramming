#include <bits/stdc++.h>

using namespace std;

bool dfs(int i, vector<bool>& vis, vector<set<int>>& adj, bool& chain) {
  vis[i] = true;
  if (adj[i].size() == 1) {
    chain = true;
  }
  for (int nb : adj[i]) {
    if (!vis[nb]) {
      chain = dfs(nb, vis, adj, chain) || chain;
    }
  }
  return chain;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<set<int>> adj(N + 1);
    for (int i = 0; i < N; i++) {
      int u;
      cin >> u;
      adj[i+1].insert(u);
      adj[u].insert(i+1);
    }
    vector<bool> vis(N + 1, false);
    int cycl = 0, chain = 0;
    for (int i = 1; i <= N; i++) {
      if (!vis[i]) {
        bool is_chain = false;
        if (dfs(i, vis, adj, is_chain)) {
          chain++;
        } else {
          cycl++;
        }
      }
    }
    cout << cycl + (chain > 0) << " " << cycl + chain << endl;
  }
  return 0;
}