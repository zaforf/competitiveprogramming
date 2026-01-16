#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;


const int MAXX = 200001;
int sieve[MAXX] = {0};

void start() {
    for (int i=2;i<MAXX;i++)
        if (!sieve[i])
            for (int j=2*i;j<MAXX;j+=i)
                sieve[j]=i;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n; cin>>n;
    vecin(a,n);
    vecin(b,n);

    int ans = INT_MAX;
    unordered_map<int,int,custom_hash> freq;
    int even = 0;
    set<int> primes;
    for (int i=0;i<n;i++) {
        int x = a[i];
        if (x % 2 == 0) even++;
        while (sieve[x]) {
            int p = sieve[x];
            while (x % p == 0) x /= p;
            if (freq[p] > 0) {
                cout << 0 << endl;
                return;
            }
            primes.insert(p);
            freq[p]++;
        }
        if (freq[x] > 0) {
            cout << 0 << endl;
            return;
        }
        if (x > 1) {
            primes.insert(x);
            freq[x]++;
        }
    }


    for (int i=0;i<n;i++) {
        int x = a[i] + 1;
        while (sieve[x]) {
            int p = sieve[x];
            while (x % p == 0) x /= p;
            if (freq[p] > 0 && a[i] % p != 0) {
                ans = min(ans, b[i]);
            }
        }
        if (freq[x] > 0 && a[i] % x != 0) {
            ans = min(ans, b[i]);
        }
    }

    int first_min_b = INT_MAX, first_min_idx = -1;
    for (int i=0;i<n;i++) {
        if (a[i] % 2 == 1) {
            if (b[i] < first_min_b) {
                first_min_b = b[i];
                first_min_idx = i;
            }
        }
    }
    int second_min_b = INT_MAX;
    for (int i=0;i<n;i++) {
        if (a[i] % 2 == 1 && i != first_min_idx) {
            if (b[i] < second_min_b) {
                second_min_b = b[i];
            }
        }
    }

    if (even == 0)
        ans = min(ans, first_min_b + second_min_b);
    else
        ans = min(ans, first_min_b);

    for (int i=0;i<n;i++)
        first_min_b = min(first_min_b, b[i]);

    for (int i=0;i<n;i++) {
        if (b[i] != first_min_b) continue;
        int min_cost = INT_MAX;
        for (auto p : primes) {
            if (a[i] % p != 0) {
                min_cost = min(min_cost, p - (a[i] % p));
            }
        }
        ans = (int) min((long long) ans, min_cost * 1ll * b[i]);
        break;
    }
    cout << ans << endl;
}

int main() {
    start();
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}