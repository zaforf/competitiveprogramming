#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n,l,r; cin>>n>>l>>r;
    vector<int> sol;
    for (int i=1;i<=n;i++){ 
        if (l+i-(l%i)-(l%i==0 ? i : 0) > r) {
            cout<<"NO\n";
            return 0;
        }
        else
            sol.push_back(l+i-(l%i)-(l%i==0 ? i : 0));
    }
    cout<<"YES\n";
    for (auto a : sol) {cout<<a<<" ";}
    cout<<"\n";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    while (n--) {
        solve();
    }
}