#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n, m; cin >> n >> m;
    vecin(d,n);
    vector<array<int,2>> qs;
    unordered_set<int> used;
    for (int i=0;i<m;i++) {
        char a; int b; cin >> a >> b;
        qs.push_back({a=='Q',b});
        if (a=='X') used.insert(b);
    }
    reverse(qs.begin(), qs.end());
    vector<int> dp(100001, 1e9);
    dp[0] = 0;
    for (int c : d) {
        if (used.find(c) == used.end()) {
            for (int j=c;j<=100000;j++) {
                if (dp[j-c] != -1) dp[j] = min(dp[j], dp[j-c]+1);
            }
            dp[c] = min(dp[c], 1);
        }
    }
    vector<int> ans;
    for (auto [t,x] : qs) {
        if (t) {
            ans.push_back(dp[x] == 1e9 ? -1 : dp[x]);
        } else {
            for (int j=x;j<=100000;j++) {
                if (dp[j-x] != -1) dp[j] = min(dp[j], dp[j-x]+1);
            }
            dp[x] = min(dp[x], 1);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int v : ans)
        cout << v << endl;

    return 0;
}