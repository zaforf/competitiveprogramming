#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for (int& i : a) cin>>i;
    map<int, int> cnt;
    for (int v : a) cnt[v]++;
    vector<pair<int,int>> freqs;
    for (auto& p : cnt) freqs.emplace_back(p.second, p.first);
    int last_over_one = -1;
    for (int i=0;i<freqs.size();i++) {
        if (freqs[i].first > 1) {
            if (last_over_one != -1 && freqs[i].second-freqs[last_over_one].second == i - last_over_one) {
                cout<<"YES\n";
                return;
            }
            last_over_one = i;
        } if (freqs[i].first >= 4) {
            cout<<"YES\n";
            return;
        }
    
    }
    cout<<"NO\n";

}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}