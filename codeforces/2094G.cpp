#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int q; cin>>q;
    int curr = 0, rev = 0, sum = 0, last = 0;
    int t, k, sz = 0;
    deque<int> dq; int d = 1;
    for (int i=0;i<q;i++) {
        cin>>t;
        if (sz && d == 1)
            last = dq.back();
        else
            last = dq.front();

        if (t == 1) {
            curr = curr + sum - sz * last;
            rev = rev - 2 * sum + 2 * last + 2 * (sz-1) * last;

            if (d == 1) {
                int v = dq.back(); dq.pop_back();
                dq.push_front(v);
            } else {
                int v = dq.front(); dq.pop_front();
                dq.push_back(v);
            }
        } else if (t == 2) {
            curr += rev;
            rev = -rev;

            d = -d;
        } else if (t == 3) {
            cin>>k;
            curr += (sz+1) * k;
            rev = rev + sum - sz * k;
            sum += k;
            sz++;

            if (d == 1)
                dq.push_back(k);
            else
                dq.push_front(k);
        }
        cout << curr << endl;
    }
    
}

int32_t main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}