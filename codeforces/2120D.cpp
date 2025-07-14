#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1000000007;

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

int comb(int a, int b) {
    if (b > a || b < 0) return 0;
    if (b == 0 || b == a) return 1;
    int num = 1, den = 1;
    for (int i = 0; i < b; ++i) {
        num = num * (a - i) % MOD;
        den = den * (i + 1) % MOD;
    }
    return num * exp(den, MOD - 2) % MOD;
}


void solve() {
    int a,b,k; cin>>a>>b>>k;
    int n = ((a-1)*k+1)%MOD;
    cout << n << " ";
    int m = (b-1)*comb(n, a)%MOD*k%MOD;
    cout << (m+1)%MOD << endl;
    
}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}