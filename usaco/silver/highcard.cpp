#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

int main() {
    freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
    int n;cin>>n;
    bool cards[2*n+1] = {false};
    vector<int> el;
    for (int i=0;i<n;i++) {
        int inp;cin>>inp;
        el.push_back(inp);
        cards[inp] = true;
    }
    set<int> avail;
    for (int i=1;i<2*n+1;i++) {
        if (!cards[i]) {
            avail.insert(i);
        }
    }
    sort(begin(el),end(el));
    int ans=0;
    for (int i=0;i<n;i++) {
        auto find = avail.upper_bound(el[i]);
        if (find != avail.end()) {
            ans++;
            avail.erase(find);
        }
        else {
            avail.erase(avail.begin());
        }
    }
    cout<<ans;
}