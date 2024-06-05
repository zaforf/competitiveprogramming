#include <bits/stdc++.h>

using namespace std;
const int MAXN = 200001;
int log_2[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q; cin>>n>>q;
    log_2[1]=0;
    for (int i=2;i<MAXN;i++)
        log_2[i]=log_2[i/2]+1;
    vector<int> vals(n);
    for (int i=0;i<n;i++)
        cin>>vals[i];
    vector<vector<int>> sparse(log_2[n]+1);
    for (int i=0;i<n;i++)
        sparse[0].push_back(vals[i]);
    for (int j=1;j<=log_2[n];j++) {
        for (int i=0;i<n-(1<<j)+1;i++){
            sparse[j].push_back(min(sparse[j-1][i],sparse[j-1][i+(1<<(j-1))]));
        }
    }
    for (int i=0;i<q;i++) {
        int a,b;cin>>a>>b;
        cout << min(sparse[log_2[b-a+1]][a-1],sparse[log_2[b-a+1]][b-(1<<log_2[b-a+1])]) << "\n";
    }
}