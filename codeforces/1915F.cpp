#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long

void solve() {
    int n; cin>>n;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        intervals[i] = {x, y};
    }
    sort(intervals.begin(), intervals.end());
    
    ordered_set<int> open;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // increment by end points in open greater than this end point
        int end = intervals[i].second;
        int count = open.order_of_key(end);
        ans += i - count;
        // add this end point to open
        open.insert(end);
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