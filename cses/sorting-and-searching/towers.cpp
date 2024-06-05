#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    multiset<int> towers;
    for (int i=0;i<n;i++){ 
        int inp; cin>>inp;
        auto find = towers.upper_bound(inp);
        if (find==towers.end()) {
            towers.insert(inp);
        }
        else {
            towers.erase(find);
            towers.insert(inp);
        }
    }
    cout << towers.size();
}