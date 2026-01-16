#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n; cin>>n;
    vector<array<int,2>> a(n);
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    vector<int> dp(n,0);
    for (int i=2;i<n;i++){
        int lb = max(a[i][0], max(a[i-1][0], a[i-2][0]));
        int rb = min(a[i][1], min(a[i-1][1], a[i-2][1]));
        if (lb-1 <= i-2 && i <= rb-1) {
            dp[i] = ((i>2)?dp[i-3]:0) + 1;
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n-1] << endl;
    return 0;
}