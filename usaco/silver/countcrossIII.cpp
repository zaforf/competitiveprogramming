#include <bits/stdc++.h>
using namespace std;

bool roads[101][101][101][101];
bool cow[101][101];
bool vis[101][101];
vector<int> comps;
int N,K,R;

void dfs(int i,int j,int ccomp) {
    vis[i][j]=true;
    if (cow[i][j])
        comps[ccomp]++;
    if (i-1>0 && !vis[i-1][j] && !roads[i][j][i-1][j])
        dfs(i-1,j,ccomp);
    if (j-1>0 && !vis[i][j-1] && !roads[i][j][i][j-1])
        dfs(i,j-1,ccomp);
    if (i+1<=N && !vis[i+1][j] && !roads[i][j][i+1][j])
        dfs(i+1,j,ccomp);
    if (j+1<=N && !vis[i][j+1] && !roads[i][j][i][j+1])
        dfs(i,j+1,ccomp);
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    cin>>N>>K>>R;
    for (int i=0;i<R;i++) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        roads[a][b][c][d]=true;
        roads[c][d][a][b]=true;
    }
    for (int i=0;i<K;i++) {
        int a,b;cin>>a>>b;
        cow[a][b]=true;
    }
    int ccomp=0;
    for (int i=1;i<N+1;i++) {
        for (int j=1;j<N+1;j++) {
            if (cow[i][j]&&!vis[i][j]) {
                comps.push_back(0);
                dfs(i,j,ccomp);
                ccomp++;
            }
        }
    }
    int ans=0;
    for (int i=0;i<comps.size();i++)
        for (int j=i+1;j<comps.size();j++)
            ans += comps[i]*comps[j];
    cout<<ans;
    return 0;
}