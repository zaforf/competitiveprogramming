#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;
#define int long long

int32_t main() {
    int n, m, k; cin >> n >> m >> k;
    unordered_set<int> in;
    int start;
    for (int i=0;i<n;i++) {
        int x; cin >> x;
        if (i==k-1) start = x;
        else in.insert(x);
    }
    vector<pair<char,int>> operations;
    for (int i=0;i<m;i++) {
        char c; int x; cin >> c >> x;
        operations.push_back({c,x});
    }
    queue<int> q;
    q.push(start);
    unordered_map<int,int> rev;
    rev[start] = -1;
    int end = -1, end_d = 0;
    for (int d = 0; d < 10001; d++) {
        int sz = q.size();
        if (sz == 0) break;
        for (int i=0;i<sz;i++) {
            int cur = q.front(); q.pop();
            if (!in.count(cur)) {
                end = cur;
                end_d = d;
                break;
            }
            for (int j=0;j<m;j++) {
                auto [c,x] = operations[j];
                // +, -, *, /
                int nxt;
                if (c == '+') nxt = cur + x;
                else if (c == '-') nxt = cur - x;
                else if (c == '*') nxt = cur * x;
                else if (c == '/') {
                    if (x == 0) continue;
                    nxt = cur / x;
                }
                if (nxt < 0) continue;
                if (!rev.count(nxt)) {
                    rev[nxt] = j;
                    q.push(nxt);
                }
            }
        }
        if (end != -1) break;
    }
    if (end == -1) cout << -1 << endl;
    else {
        cout << end_d << endl;
        vector<int> ans;
        while (end != start) {
            int op = rev[end];
            auto [c,x] = operations[op];
            if (c == '+') end -= x;
            else if (c == '-') end += x;
            else if (c == '*') end /= x;
            else if (c == '/') end *= x;
            ans.push_back(op+1);
        }
        reverse(ans.begin(), ans.end());
        for (auto _ : ans) cout << _ << endl;
    }

    return 0;
}