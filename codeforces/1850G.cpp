#include <bits/stdc++.h>
using namespace std;
#define int long long

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
    map<int, int> row, col, diagd, diagu;
    int ans = 0;
    for (int i=0;i<n;i++) {
        int x, y; cin>>x>>y;
        ans += 2*row[x] + 2*col[y] + 2*diagd[x+y] + 2*diagu[x-y];
        row[x]++;
        col[y]++;
        diagd[x+y]++;
        diagu[x-y]++;
    }
    cout << ans << endl;
}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}