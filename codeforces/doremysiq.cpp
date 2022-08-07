#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n,iq; cin>>n>>iq;
    vector<int> v(n);
    for (int i=0;i<n;i++)
        cin>>v[i];
    int g=0;
    vector<int> ans(n,0);
    for (int i=n-1;i>=0;i--) {
        if (v[i]>g && g<iq) {
            g+=1;
            ans[i] = 1;
        } else if(v[i]<=g)
            ans[i] = 1;
    }
    for (auto a : ans) {cout<<a;}
    cout<<"\n";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while (t--) {
        solve();
    }
}