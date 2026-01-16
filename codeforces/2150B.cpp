#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

const int MOD = 998244353;
const int MAXN = 1000001;

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

int comb(int a, int b) {
    if (b>a || a<0 || b<0) return 0;
    return fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}


void solve() {
    int n; cin>>n;
    vecin(a, n);
    int remaining = n & 1 ? 1 : 2;
    remaining -= 2;
    int ans = 1;
    for (int i=(n+1)/2-1;i>=0;i--) {
        remaining += 2;
        ans = comb(remaining, a[i]) * ans % MOD;
        remaining -= a[i];
    }
    if (remaining != 0) ans = 0;
    if (accumulate(a.begin(), a.end(), 0LL) != n) ans = 0;
    cout << ans << endl;


}

int32_t main() {
    factorial();
    inverses();
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}