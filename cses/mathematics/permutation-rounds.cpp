#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int binexp(int a, int b) {
    int ret=1;
    while (b) {
        if (b&1) {
            ret *= a;
            ret %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ret;
}

const int MAXX = 200001;
int sieve[MAXX];

void start() {
    for (int i=2;i<MAXX;i++)
        if (!sieve[i])
            for (int j=2*i;j<MAXX;j+=i)
                sieve[j]=i;
}

int32_t main() {
    start();
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<bool> vis(n);
    unordered_map<int, int> ans, curr;
    for (int i=0;i<n;i++) {
        if (vis[i]) continue;
        curr.clear();
        int j = i, cnt = 0;
        do {
            vis[j] = true;
            j = a[j] - 1;
            cnt++;
        } while (j != i);
        
        while (cnt > 1) {
            int p = sieve[cnt];
            if (p == 0) p = cnt;
            curr[p]++;
            ans[p] = max(ans[p], curr[p]);
            cnt /= p;
        }
    }
    int res = 1;
    for (auto& [p, c] : ans)
        res = res * binexp(p, c) % MOD;
    cout << res;
    return 0;
}