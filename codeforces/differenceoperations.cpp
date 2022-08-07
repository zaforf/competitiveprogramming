#include <bits/stdc++.h>

using namespace std;

int solve () {
    int c; cin>>c;
    vector<int> v(c);
    for (int i=0;i<c;i++)
        cin>>v[i];
    for (int i=1;i<c;i++) {
        if (v[i]%v[0]==0 && v[i]!=0)
            continue;
        else {
            cout<<"NO\n";
            return 0;
        }
    }
    cout <<"YES\n";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for (int i=0;i<n;i++) {
        solve();
    }
}