#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n; cin >> n;
    set<array<int,2>> points;
    priority_queue<array<double,2>> pq; // {per_unit, index}
    unordered_map<int,array<int,3>> mp; // index -> {x, weight, cnt}
    double curr = 0;
    for (int i=0;i<n;i++) {
        int x, y; cin >> x >> y;
        points.insert({x,i});
        pq.push({y, i});
        mp[i] = {x, y, 1};
        curr += x*y;
    }
    double ans = 0;
    int d = curr < 0 ? 1 : -1;
    curr = abs(curr);
    while (abs(curr) > 1e-9) {
        auto [per_unit, i] = pq.top(); pq.pop();
        auto [x, weight, cnt] = mp[i];
        int nb_x = -1, nb_i = -1;
        if (d == 1) {
            auto it = points.upper_bound({x, i});
            if (it != points.end()) {
                nb_x = (*it)[0];
                nb_i = (*it)[1];
            }
        } else {
            auto it = points.lower_bound({x, i});
            if (it != points.begin()) {
                --it;
                nb_x = (*it)[0];
                nb_i = (*it)[1];
            }
        }
        if (nb_x == -1) {
            // unbounded
            ans += (double) curr / per_unit;
            curr = 0;
        } else {
            double diff = abs(nb_x - x);
            double can_go = (double) curr / (weight * cnt);
            if (can_go >= diff) {
                // can reach neighbor
                ans += diff * cnt;
                curr -= weight * cnt * diff;
                // merge
                points.erase({x, i});
                mp[nb_i][1] += weight;
                mp[nb_i][2] += cnt;
                pq.push({mp[nb_i][1], nb_i});
            } else {
                ans += can_go;
                curr = 0;
            }


        }
    }
    cout << ans << endl;

    return 0;
}