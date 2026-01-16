#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n), tot_b(n); vector<queue<int>> b(n);
    for (int& i : a) cin>>i;
    for (int i=0;i<n;i++) {
        int m; cin>>m;
        b[i].push(m);
        tot_b[i] = m;
    }
    set<int> done;
    for (int i=0;i<n;i++) done.insert(i);
    queue<int> bfs;
    for (int i=0;i<n;i++)
        if (tot_b[i] >= a[i])
            bfs.push(i);
    
    int ans = 1;
    vector<int> def(n);
    while (!bfs.empty()) {
        auto idx = bfs.front(); bfs.pop();
        // cout << "idx: " << idx << endl;
        auto it = done.find(idx);
        if (it != done.end()) {
            int before = it == done.begin() ? *done.rbegin() : *prev(it);
            done.erase(idx);
            if (done.empty()) before = -1;
            int c = def[idx];
            if (tot_b[before] < a[before]) {
                def[before] += def[idx];
            }
            while (a[idx]) {
                int first = b[idx].front(); b[idx].pop();
                tot_b[idx] -= first;
                // cout << "eat from b[" << idx << "] = " << first << endl;
                int t = min(first, a[idx]);
                a[idx] -= t;
                first -= t;
                if (before >= 0) {
                    // cout << "push to b[" << before << "] = " << first << endl;
                    b[before].push(first);
                    tot_b[before] += first;
                }
                c++;
            }
            ans = max(ans, c);
            if (done.empty()) break;

            while (!b[idx].empty()) {
                int first = b[idx].front(); b[idx].pop();
                tot_b[idx] -= first;
                // cout << "push to b[" << before << "] = " << first << endl;
                b[before].push(first);
                tot_b[before] += first;
            }
            if (tot_b[before] >= a[before])
                bfs.push(before);
            else {
                // cout << "clearing " << before << endl;
                def[before] += b[before].size();
                b[before] = queue<int>();
                a[before] -= tot_b[before];
                tot_b[before] = 0;

            }

        }
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