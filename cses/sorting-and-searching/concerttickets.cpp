#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    multiset<int> tickets;
    int ntick,ncust; cin >> ntick >> ncust;
    for (int i=0;i<ntick;i++) {
        int inp; cin >> inp; tickets.insert(inp);
    }
    for (int i=0;i<ncust;i++) {
        int req; cin >> req; auto e = tickets.upper_bound(req);
        if (e==tickets.begin()) {
            cout << -1 << "\n";
        }
        else {
            cout << *(--e) << "\n";
            tickets.erase(e);
        }
    }
}
 