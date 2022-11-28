#include <bits/stdc++.h>
using namespace std;

int num=0;
vector<string> grid;
vector<vector<int>> comps;
vector<vector<bool>> vis;
void dfs(int i,int j,int n) {
    if (i<0 || i>=n || j<0 || j>=n || grid[i][j]=='.') {
        comps[num][1]-=1;
        return;
    }
    if (vis[i][j])
        return;
    vis[i][j] = true;
    comps[num][0]+=1;
    dfs(i-1,j,n);
    dfs(i,j+1,n);
    dfs(i+1,j,n);
    dfs(i,j-1,n);
    return;
}

int main() {
    freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
    int n;cin>>n;
    grid.resize(n);
    comps.resize(n*n,vector<int>(2,0));
    vis.resize(n, vector<bool>(n));
    for (int i=0;i<n;i++)
        cin>>grid[i];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j]!='.' && !vis[i][j]) {
                dfs(i,j,n);num+=1;
            }
        }
    }
    sort(comps.begin(),comps.end(),greater<vector<int>>());
    cout<<comps[0][0]<<" "<<-comps[0][1];
    return 0;
}