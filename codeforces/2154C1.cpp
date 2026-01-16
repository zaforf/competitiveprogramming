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

void solve() {
    int n; cin>>n;
    vecin(a,n);
    vecin(b,n);
    unordered_map<int,int> freq;
    int even = 0;
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
            freq[p]++;
        }
        if (freq[x] > 0) {
            cout << 0 << endl;
            return;
        }
        if (x > 1) freq[x]++;
    }
    
    for (int i=0;i<n;i++) {
        int x = a[i]+1;
        while (sieve[x]) {
            int p = sieve[x];
            while (x % p == 0) x /= p;
            if (freq[p] > 0) {
                cout << 1 << endl;
                return;
            }
        }
        if (freq[x] > 0) {
            cout << 1 << endl;
            return;
        }
    }



    if (even == 0)
        cout << 2 << endl;
    else
        cout << 1 << endl;
}

int main() {
    start();
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}