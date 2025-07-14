#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    deque<int> dq;
    int ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (i >= k) {
            ans ^= sum;
            sum -= dq.front();
            dq.pop_front();
        }
        dq.push_back(x);
        sum += x;
        x = (a * x + b) % c;
    }
    ans ^= sum;
    cout << ans << endl;
    return 0;
}