#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(n/2), p(n,1), o(n, -1);
    map<int,int> pring;
    for (int i = 0; i < n/2; i++) {
        cin >> a[i];
        p[a[i]-1] -= 2;
        o[a[i]-1] = i;
    }
    set<int> in;
    priority_queue<pair<int,int>> q;
    int c = 0;
    for (int i=0;i<n;i++) {
        c += p[i];
        if (p[i] < -1 || c < 0) {
            cout << "-1\n";
            return;
        }
        if (p[i] < 0) q.push({o[i], i});
        else in.insert(i);
        if (c == 0) {
            while (!q.empty()) {
                auto qit = q.top(); q.pop();
                int x = qit.second;
                auto it = in.upper_bound(x);
                it--;
                pring[x+1] = *it + 1;
                in.erase(*it);
            }
        }
    }
    for (int v : a)
        cout << pring[v] << " " << v << " ";
    cout << endl;

}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}