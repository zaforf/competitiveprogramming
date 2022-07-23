#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,d; cin>>n>>d;
    vector<int> coins(n);
    for (int& c : coins) cin>>c;

    vector<int> dp(d+1,1e9);
    dp[0] = 0;
    for (int i=1;i<d+1;i++) {
        for (int c : coins) {
            if (i-c>=0) dp[i] = min(dp[i],dp[i-c]+1);
        }
    }
    cout << (dp[d] == 1e9 ? -1 : dp[d]);
}