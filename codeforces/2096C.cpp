#include <bits/stdc++.h>
using namespace std;
#define int long long

const int BAD = 1e14;

void solve() {
    int n; cin>>n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin>>grid[i][j];
    vector<int> a(n), b(n);
    for (int& i : a) cin>>i;
    for (int& i : b) cin>>i;
    vector<array<int, 2>> dp(n, {0, 0});
    dp[0][1] = a[0];
    for (int i=1;i<n;i++) {
        bool eq = 0, less = 0, great = 0;
        for (int j=0;j<n;j++) {
            if (grid[i][j] == grid[i-1][j] + 1) less = 1;
            else if (grid[i][j] == grid[i-1][j]) eq = 1;
            else if (grid[i][j] == grid[i-1][j] - 1) great = 1;
        }
        // turn it off
        dp[i][0] = min(eq ? BAD : dp[i-1][0], less ? BAD : dp[i-1][1]);

        // turn it on
        dp[i][1] = min(great ? BAD : (dp[i-1][0] + a[i]), eq ? BAD : (dp[i-1][1] + a[i]));

    }
    int down = min(dp[n-1][0], dp[n-1][1]);
    // transpose the grid
    vector<vector<int>> gridT(n, vector<int>(n));
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            gridT[j][i] = grid[i][j];
    dp = vector<array<int, 2>>(n, {0, 0});
    dp[0][1] = b[0];
    for (int i=1;i<n;i++) {
        bool eq = 0, less = 0, great = 0;
        for (int j=0;j<n;j++) {
            if (gridT[i][j] == gridT[i-1][j] + 1) less = 1;
            else if (gridT[i][j] == gridT[i-1][j]) eq = 1;
            else if (gridT[i][j] == gridT[i-1][j] - 1) great = 1;
        }
        // turn it off
        dp[i][0] = min(eq ? BAD : dp[i-1][0], less ? BAD : dp[i-1][1]);

        // turn it on
        dp[i][1] = min(great ? BAD : (dp[i-1][0] + b[i]), eq ? BAD : (dp[i-1][1] + b[i]));
    }
    int right = min(dp[n-1][0], dp[n-1][1]);
    cout << ((down + right >= BAD)? -1 : down + right) << "\n";


}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}