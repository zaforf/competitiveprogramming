#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;


void solve() {
    int n,m,d; cin>>n>>m>>d;
    vector<vector<int>> row_inds(n, vector<int>(1,-d-100));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m+1, vector<int>(2, 0)));
    for (int i=0;i<n;i++) {
        string s; cin>>s;
        for (int j=0;j<m;j++)
            if (s[j] == 'X')
                row_inds[i].push_back(j);
    }
    int dist = sqrt(d*d-1);
    for (int i=0;i<n;i++) {
        int row_inds_sz = row_inds[i].size();
        for (int k=1;k>=0;k--) {
            int l = 0, r = 1; 
            for (int j=1;j<row_inds_sz;j++) {
                if (k == 1) {
                    if (i == 0) {
                        dp[i][j][1] = dp[i][j-1][1] + 1;
                    }
                    else {
                        dp[i][j][1] = dp[i][j-1][1];
                        while (l < row_inds[i-1].size() && row_inds[i-1][l] < row_inds[i][j] - dist) l++;
                        l--;
                        while (r < row_inds[i-1].size() && row_inds[i-1][r] <= row_inds[i][j] + dist) r++;
                        r--;
                        dp[i][j][1] = (dp[i][j][1] + dp[i-1][r][0] - dp[i-1][l][0] + MOD) % MOD;
                    }
                } else {
                    dp[i][j][0] = dp[i][j-1][0];
                    while (l < row_inds[i].size() && row_inds[i][l] < row_inds[i][j] - d) l++;
                    l--;
                    while (r < row_inds[i].size() && row_inds[i][r] <= row_inds[i][j] + d) r++;
                    r--;
                    if (row_inds[i][r] >= row_inds[i][j] - d)
                        dp[i][j][0] = (dp[i][j][0] + dp[i][r][1] - dp[i][l][1] + MOD) % MOD;
                }
            }
        }
    }
    cout << dp[n-1][row_inds[n-1].size()-1][0] << endl;


}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}