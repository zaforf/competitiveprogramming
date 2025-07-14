#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<array<int,2>> pairs(n);
    for (int i=0;i<n;i++) {
        cin>>pairs[i][0];
        pairs[i][1] = i;
    }
    sort(pairs.begin(), pairs.end(), greater<>());
    unordered_set<int> adj;
    int ans = 0;
    for (auto& p : pairs) {
        int i = p[1];
        if (adj.find(i) == adj.end())
            ans++;
        adj.insert(i + 1);
        adj.insert(i - 1);
    }
    cout << ans << endl;
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}