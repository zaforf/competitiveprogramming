#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x; cin>>n>>x;
    multiset<int> spaces; spaces.insert(n);
    multiset<int> lights;
    lights.insert(0);
    for (int i=0;i<x;i++) {
        int inp; cin>>inp;
        if (lights.size()==0) {
            spaces.erase(spaces.find(n));
            spaces.insert(n-inp);spaces.insert(inp);
            lights.insert(inp);
        }
        else {
            auto last = lights.lower_bound(inp);
            int dif,max;
            if (last != lights.end()) {
                dif = *last;
                max = *last;
            }
            else {
                max = n;
                dif = n;
            }
            last--; dif = dif - *last;
            spaces.erase(spaces.find(dif));
            spaces.insert(inp-*last);
            spaces.insert(max-inp);
            lights.insert(inp);
        }
        cout << *(--spaces.end()) << " ";
    }
}