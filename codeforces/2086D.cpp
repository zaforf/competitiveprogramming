#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
const int MAXN = 500001;

int exp(int a,int b) {
    int ret = 1;
    a %= MOD;
    while (b) {
        if (b&1) ret = ret * a % MOD;
        a = a * a % MOD;
        b>>=1;
    }
    return ret;
}

int fac[MAXN+1];
int inv[MAXN+1];

void factorial() {
    fac[0] = 1;
    for (int i=1;i<MAXN+1;i++) fac[i] = fac[i-1]*i%MOD;
}

void inverses() {
    inv[MAXN] = exp(fac[MAXN],MOD-2);
    for (int i=MAXN-1;i>=0;i--) inv[i] = inv[i+1]*(i+1)%MOD;
}

int letters = 26;

void solve() {
    vector<int> cnt(letters);
    for (int& i : cnt) cin >> i;
    int tot = accumulate(cnt.begin(), cnt.end(), 0), ans = 0;
    int rep = 1;
    for (int i = 0; i < letters; i++)
        rep = rep * inv[cnt[i]] % MOD;
    rep = rep * fac[(tot + 1)/2] % MOD * fac[tot/2] % MOD;
    vector<int> dp(tot + 1);
    dp[0] = 1;
    for (int i = 0; i < letters; i++) {
        for (int j = tot; j >= cnt[i] && cnt[i]; j--) {
            dp[j] = (dp[j] + dp[j - cnt[i]]) % MOD;
        }
    }

    cout << dp[(tot+1)/2]* rep % MOD << endl;

}

int32_t main() {
    factorial(); inverses();
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}