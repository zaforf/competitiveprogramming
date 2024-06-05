#include <bits/stdc++.h>
using namespace std;

bool vis[100005];

void dfs(int node,const vector<vector<int>>& graph) {
    vis[node] = true;
    for (int nb : graph[node])
        if (!vis[nb])
            dfs(nb,graph);
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int N,M;cin>>N>>M;
    vector<vector<int>> graph(N+1,vector<int>()),rev(N+1,vector<int>());
    for (int i=0;i<M;i++) {
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        rev[b].push_back(a);
    }
    dfs(1,graph);
    for (int i=1;i<N+1;i++) {
        if (!vis[i]) {
            cout<<"NO\n1 "<<i;
            return 0;
        }
    }
    memset(vis,false,sizeof(vis));
    dfs(1,rev);
    for (int i=1;i<N+1;i++) {
        if (!vis[i]) {
            cout<<"NO\n"<<i<<" 1";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}