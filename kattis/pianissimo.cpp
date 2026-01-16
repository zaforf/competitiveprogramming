#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n, k; cin >> n >> k;
    unordered_map<string,int> conv;
    conv["ppp"] = 0;
    conv["pp"] = 1;
    conv["p"] = 2;
    conv["mp"] = 3;
    conv["mf"] = 4;
    conv["f"] = 5;
    conv["ff"] = 6;
    conv["fff"] = 7;

    vecin(a, n);
    vector<array<int,2>> b(k);
    for (int i=0;i<k;i++) {
        string t; 
        cin >> b[i][0] >> t;
        b[i][1] = -conv[t];
    }
    vector<array<int,2>> ps;
    int r = 0;
    for (int i=0;i<n;i++) {
        if (r<k-1 && i+1 == b[r+1][0]) r++;
        ps.push_back({a[i], b[r][1]});
    }
    sort(ps.begin(), ps.end());
    
    vector<int> cnt(8);
    long long ans = 0;
    for (int i=n-1;i>=0;i--) {
        for (int j=0;j<-ps[i][1];j++) ans += cnt[j];
        cnt[-ps[i][1]]++;
    }
    cout << ans << endl;

    return 0;
}