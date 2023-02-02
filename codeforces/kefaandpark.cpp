#include <bits/stdc++.h>
using namespace std;

bool vis[100001];
int cat[100001];
vector<vector<int>> adj;
int N,ncat;

int dfs(int node,int catcnt, int parent) {
    int ret=0;
    vis[node]=true;
    for (int nb:adj[node])
        if (!vis[nb]&&catcnt+cat[node]<=ncat)
            ret += dfs(nb,(cat[node]?catcnt+cat[node]:0),node);
    if (adj[node].size()==1 && adj[node][0]==parent && catcnt+cat[node]<=ncat)
        ret+=1;
    return ret;
}

int main() {
    cin>>N>>ncat;
    for (int i=1;i<N+1;i++)
        cin>>cat[i];
    adj.resize(N+1,vector<int>());
    for (int i=0;i<N-1;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<dfs(1,0,0);
    return 0;
}