#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, s, x, inp; cin>>n>>s>>x;
    map<int,int> cnt;
    vector<int> queue(1);
    int p = 0, ans = 0;
    for (int i=0;i<n;i++) {
        cin>>inp;
        p += inp;
        if (inp > x) {
            cnt.clear();
            queue.clear();
            queue.push_back(p);
            continue;
        } else if (inp == x) {
            for (int v : queue)
                cnt[v]++;
            queue.clear();
        }
        queue.push_back(p);
        ans += cnt[p - s];
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