#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    long long saved = 0;
    set<int> avail, prio;
    for (int i=0;i<n;i++) {
        if (s[i] == '1')
            avail.insert(i+1);
        else
            prio.insert(i+1);
    }
    
    for (int i=n-1;i>=0;i--) {
        if (!avail.count(i+1) && !prio.count(i+1))
            continue;
        int use;
        if (prio.empty())
            use = *avail.begin();
        else
            use = *prio.rbegin();
        if (s[i] == '1' && i+1 > use) {
            saved += i+1;
            avail.erase(use);
            prio.erase(use);
        }
        avail.erase(i+1);
        prio.erase(i+1);
    }
    cout << 1ll*n*(n+1)/2 - saved << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}