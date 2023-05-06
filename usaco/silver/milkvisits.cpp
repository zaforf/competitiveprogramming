#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100001;
int comp[MAX_N];
bool breed[MAX_N]; // true H, false G
bool vis[MAX_N];
vector<vector<int>> adj;
int N,M,ccomp;

void dfs(int i) {
    comp[i]=ccomp;
    vis[i]=true;
    for (int nb : adj[i])
        if(!vis[nb]&&breed[i]==breed[nb])
            dfs(nb);
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin>>N>>M;
    adj.resize(N+1,vector<int>());
    string breeds;cin>>breeds;
    for (int i=0;i<N;i++)
        breed[i+1] = (breeds[i]=='H');
    for (int i=0;i<N-1;i++) {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ccomp = 0;
    for (int i=1;i<N+1;i++)
        if(!vis[i]) {
            dfs(i);
            ccomp++;
        }
    for (int i=0;i<M;i++) {
        int a,b;char c; cin>>a>>b>>c;
        if (comp[a]!=comp[b])
            cout<<1;
        else if (breed[a]==(c=='H'))
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}