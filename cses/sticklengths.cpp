#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()

int main() {
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n;cin>>n;
    vector<int> stx(n);
    for (int i=0;i<n;i++)
        cin>>stx[i];
    sort(all(stx));
    long long ans=0;
    for (int & a : stx)
        ans+=abs(stx[n/2]-a);
    cout<<ans;
    return 0;
}