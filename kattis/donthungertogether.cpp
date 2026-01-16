#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

bool works(double m, int k, vector<array<int,2>> &a) {
    // min heap
    priority_queue<pair<int,double>, vector<pair<int,double>>, greater<pair<int,double>>> pq;
    int n = a.size();
    for (int i = 0;i<n;i++) {
        pq.push({a[i][1], a[i][0]});
        double c = m*k;
        while (!pq.empty() && c > 1e-9) {
            auto [t, amt] = pq.top(); pq.pop();
            if (t < i+1) continue;
            double take = min(amt, c);
            amt -= take;
            c -= take;
            if (amt > 1e-9) pq.push({t, amt});
        }
        if (c > 1e-9) return false;
    }
    return true;
}



int main() {
    int n, k; cin >> n >> k;
    vector<array<int,2>> a(n);
    for (int i=0;i<n;i++) cin >> a[i][0] >> a[i][1];
    double l = 0, r = 1e9;
    for (int it=0;it<100;it++) {
        if (r-l < 1e-9) break;
        double m = (l+r)/2;
        if (works(m, k, a)) l = m;
        else r = m;
    }
    if (l < 1e-9) cout << -1 << endl;
    else cout << fixed << setprecision(15) << l << endl;
    return 0;
}