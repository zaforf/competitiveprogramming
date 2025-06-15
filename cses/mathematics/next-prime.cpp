#include <bits/stdc++.h>
using namespace std;
#define int long long

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i += 1 + (i & 1))
        if (n % i == 0)
            return false;
    return true;
}

void solve() {
    int n; cin>>n;
    do {
        n++;
    } while (!is_prime(n));
    cout << n << endl;
}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}