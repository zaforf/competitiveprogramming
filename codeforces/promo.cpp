#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    l n,q; cin>>n>>q;
    vector<l> prefix;
    prefix.push_back(0);
    vector<l> input;
    for (int i=0;i<n;i++) {
        l inp; cin>>inp; input.push_back(inp);
    }
    sort(input.begin(),input.end());
    for (int i=0;i<n;i++) {
        prefix.push_back(prefix[i]+input[i]);
    }
    for (int i=0;i<q;i++) {
        l a,b; cin>>a>>b;
        cout << prefix[n-a+b]-prefix[n-a]<<"\n";
    }
}