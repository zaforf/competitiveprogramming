#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n, k; cin >> n >> k;
    vector<vector<vector<bitset<2501>>>> dp(n+1, vector<vector<bitset<2501>>>(41, vector<bitset<2501>>(401)));
    vector<vector<vector<bool>>> vis(n+1, vector<vector<bool>>(41, vector<bool>(401, false)));
    dp[0][0][0][0] = 1;
    vis[0][0][0] = 1;
    string s; cin >> s;
    
    for (int i=1;i<=n;i++) {
        char c = s[i-1];
        bool all = (c == '?');
        bool none = !(c == 'N' || c == 'A' || c == 'C');
        for (int j=0;j<=40;j++) {
            for (int x=0;x<=400;x++) {
                if (!vis[i-1][j][x]) continue;
                // N
                if (all || c == 'N') {
                    dp[i][j+1][x] |= dp[i-1][j][x];
                    vis[i][j+1][x] = true;
                }
                // A
                if (all || c == 'A') {
                    dp[i][j][x+j] |= dp[i-1][j][x];
                    vis[i][j][x+j] = true;
                }
                // C
                if (all || c == 'C') {
                    dp[i][j][x] |= (dp[i-1][j][x] << x);
                    vis[i][j][x] = true;
                }
                // Z
                if (none || all) {
                    dp[i][j][x] |= dp[i-1][j][x];
                    vis[i][j][x] = true;
                }
            }
        }
    
    }

    int en = -1, ea = -1, ec = k;
    for (int j=0;j<41;j++) {
        for (int x=0;x<401;x++) {
            if (dp[n][j][x][k]) {
                en = j;
                ea = x;
                ec = k;
                break;
            }
        }
        if (en != -1) break;
    }

    if (en == -1) {
        cout << -1 << endl;
        return 0;
    }


    int ei = n;
    string ans = s;
    while (ei > 0) {
        // try N
        char c = s[ei-1];
        if (!(c == '?' || c == 'N' || c == 'A' || c == 'C')) {
            ei--;
            continue;
        }
        if (en > 0 && dp[ei-1][en-1][ea][ec] && (c == '?' || c == 'N')) {
            ans[ei-1] = 'N';
            en--;
        } else if (ea >= en && dp[ei-1][en][ea-en][ec] && (c == '?' || c == 'A')) {
            ans[ei-1] = 'A';
            ea -= en;
        } else if (ec >= ea && dp[ei-1][en][ea][ec-ea] && (c == '?' || c == 'C')) {
            ans[ei-1] = 'C';
            ec -= ea;
        } else {
            ans[ei-1] = 'Z';
        }
        ei--;
    }
    cout << ans << endl;
    


    return 0;
}