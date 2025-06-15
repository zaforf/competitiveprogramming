#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for (int i=0;i<=k;i++)
        dp[n][i] = 1;
    for (int i=n-1;i>=0;i--) {
        int mn = 1e9;
        for (int j=0;j<k;j++) {
            if ((s[i]-'a') == j)
                dp[i][j] = 1 + dp[i+1][k];
            else
                dp[i][j] = dp[i+1][j];
            mn = min(mn, dp[i][j]);
        }
        dp[i][k] = mn;

    }
    vector<vector<int>> inds(k);
    for (int i=0;i<n;i++)
        inds[s[i]-'a'].push_back(i);
    int q; cin >> q;
    while (q --> 0) {
        string t; cin >> t;
        int i = -1;
        for (char c : t) {
            int j = c - 'a';
            auto it = upper_bound(inds[j].begin(), inds[j].end(), i);
            if (it == inds[j].end()) {
                i = n;
                break;
            } else {
                i = *it;
            }
        }
        if (i >= n)
            cout << 0 << endl;
        else
            cout << dp[i+1][k] << endl;
    }
    return 0;
}