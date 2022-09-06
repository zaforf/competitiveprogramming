#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

int n=0; vector<int> vals;

int targ(int i) {
    if (i==0)
        return 1;
    else if (i==n-1)
        return 0;
    else if (vals[i]-vals[i-1]<=vals[i+1]-vals[i])
        return 0;
    else
        return 1;
}

int main() {
    freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);
    cin>>n;
    for (int i=0;i<n;i++) {
        int inp;cin>>inp;vals.push_back(inp);
    }
    sort(vals.begin(),vals.end());
    vector<int> indeg(n, 0);
    // for (auto v : vals) 
    //     cout << v << " ";
    // cout << "\n";
    for (int i=0;i<n;i++) {
        if (targ(i))
            indeg[i+1]+=1;
        else
            indeg[i-1]+=1;
    }
    int ans=0;
    for (int i=0;i<n;i++) {
        // cout << indeg[i] << " ";
        if (indeg[i]==0)
            ans++;
        if (i<n-1 && indeg[i]==1 && indeg[i+1]==1 && targ(i)==1 && targ(i+1)==0)
            ans++;
    }
    cout << ans;
}