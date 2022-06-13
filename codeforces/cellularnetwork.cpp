#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ncit,ntow; cin >> ncit >> ntow;
    set<int> cities; set<int> towers;
    for (int i=0;i<ncit;i++) {
        int inp; cin >> inp; cities.insert(inp);
    }
    for (int i=0;i<ntow;i++) {
        int inp; cin >> inp; towers.insert(inp);
    }
    auto point = cities.begin(); int ans = -1; int b;
    while (point!=cities.end()) {
        auto find = towers.lower_bound(*point);
        if (find==towers.begin()) {
            ans = max(ans,abs(*point-*find));
        }
        else if (find==towers.end()) {
            ans = max(ans,abs(*point-*(--find)));
        }
        else {
            b = abs(*point-*find); find--;
            b = min(b,abs(*point-*find));
            ans = max(ans,b);
        }
        point++;
    }
    cout << ans;
}

