#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

const int MAXX = 1000001;
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
    vecin(a,n);
    for (int i=0;i<n;i++) {
        int x = 1;
        for (int v=2;v*v*v<=a[i];v++) {
            if (sieve[v]) continue;
            if (a[i]%(v*v) == 0) x *= v;
            while ((a[i]%v)==0) {
                a[i]/=v;
            }
        }
        if (a[i] > 1) {
            int v = sqrt(a[i]);
            if (v*v == a[i]) x *= v;
        }
        a[i] = x;
    }
    vector<int> cnt(MAXX,0);
    vector<int> ps;
    int ans = n*(n-1)/2;
    for (int v : a) {
        ps.clear();
        while (v > 1) {
            int p = (sieve[v] ? sieve[v] : v);
            ps.push_back(p);
            while (v % p == 0) v /= p;
        }
        if (ps.size() == 0) continue;
        int k = ps.size();
        
        for (int m=1;m<(1<<k);m++) {
            int x = 1;
            for (int i=0;i<k;i++) {
                if (m & (1<<i)) x *= ps[i];
            }
            if (__builtin_popcount(m) % 2 == 0) ans += cnt[x];
            else ans -= cnt[x];
            cnt[x]++;
        }
    }
    cout << ans << endl;

    return 0;
}