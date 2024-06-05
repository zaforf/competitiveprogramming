#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n;cin>>n;
    vector<pair<int,int>> movs(n);
    for (int i=0;i<n;i++)
        cin>>movs[i].second>>movs[i].first;
    sort(movs.begin(),movs.end());
    int last=0,ans=0;
    for (int i=0;i<n;i++)
        if (movs[i].second>=last) {
            last=movs[i].first;
            ans++;
        }
    cout<<ans;
    return 0;
}