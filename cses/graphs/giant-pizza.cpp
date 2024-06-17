#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<vector<int>> adj;
vector<vector<int>> adj_t;
vector<int> ord;
int p,k=0;
vector<int> comp;

void dfs(int i) {
    vis[i] = true;
    for (int nb : adj[i]) {
        if (!vis[nb])
            dfs(nb);
    }
    ord.push_back(i);
}

void assign(int i) {
    if (vis[i]) return;
    vis[i]=true;
    comp[i]=k;
    for (int nb : adj_t[i]) {
        if (comp[nb] == -1)
            assign(nb);
    }
}

int main() {
    int n;
    cin >> n >> p;
    adj.resize(2 * p + 1);
    adj_t.resize(2 * p + 1);
    comp.resize(2 * p + 1, -1);
    
    for (int i = 0; i < n; i++) {
        char s1, s2;
        int a, b;
        cin >> s1 >> a >> s2 >> b;
        int u = p + (s1 == '+' ? a : -a);
        int v = p + (s2 == '+' ? b : -b);
        int not_u = p + (s1 == '+' ? -a : a);
        int not_v = p + (s2 == '+' ? -b : b);
        adj[not_u].push_back(v);
        adj[not_v].push_back(u);
        adj_t[v].push_back(not_u);
        adj_t[u].push_back(not_v);
    }
    
    vis.resize(2 * p + 1);
    for (int i = 0; i < 2 * p + 1; i++) {
        if (!vis[i] && i != p)
            dfs(i);
    }
    reverse(ord.begin(), ord.end());
    vis.clear();vis.resize(2 * p + 1);

    for (int i : ord) {
        if (!vis[i]) {
            k++;
            assign(i);
        }
    }

    vector<int> ans(p + 1, 0);
    for (int i = 1; i <= p; i++) {
        if (comp[p - i] == comp[p + i]) {
            cout << "IMPOSSIBLE";
            return 0;
        } else
            ans[i] = (comp[p + i] < comp[p - i]) ? 1 : 2;
    }
    
    for (int i = 1; i <= p; i++)
        cout << (ans[i] == 1 ? '-' : '+') << " ";
    return 0;
}