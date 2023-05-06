#include <bits/stdc++.h>
using namespace std;

bool vis[100001];
vector<vector<pair<int,int>>> adj(100001);
int startpos[100001];
int comp[100001];
int N,M;

void dfs(int node,int width,int ccomp) {
    vis[node]=true;
    comp[node]=ccomp;
    for (pair<int,int> nb : adj[node])
        if (!vis[nb.first]&&nb.second>=width)
            dfs(nb.first,width,ccomp);
}

bool funk(int x) {
    memset(vis,false,sizeof(vis));
    int ccomp=0;
    for (int i=1;i<N+1;i++) {
        if (!vis[i]) {
            dfs(i,x,ccomp);
            ccomp++;
        }
    }
    for (int i=1;i<N+1;i++) {
        if (comp[i]!=comp[startpos[i]])
            return false;
    }
    return true;
}

int binsearch(int l,int r,function<bool(int)> func) {
    r++;
    while (l<r) {
        int med = (l+r+1)/2;
        if (func(med))
            l=med;
        else
            r=med-1;
    }
    return l;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin>>N>>M;
    for (int i=0;i<N;i++)
        cin>>startpos[i+1];
    for (int i=0;i<M;i++) {
        int a,b,w;cin>>a>>b>>w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }
    int ans=binsearch(0,1000000000,funk);
    cout<<(ans==1000000001?-1:ans);
    return 0;
}