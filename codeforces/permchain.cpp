#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for (int i=0;i<n;i++) {
        int g; cin>>g;
        vector<int> v(g);
        iota(begin(v),end(v),1);
        int j = g-1;
        cout<<g<<"\n";
        for (int i=0;i<g-1;i++) {
            for (auto t : v) {cout<<t<<" ";}
            cout<<"\n";
            swap(v[j],v[j-1]);
            j--;
        }
        for (auto t : v) {cout<<t<<" ";}
        cout<<"\n";
    }
}