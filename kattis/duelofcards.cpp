#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n; cin >> n;
    vecin(a, n);
    sort(a.begin(), a.end());
    deque<int> dq(a.begin(), a.end());
    vector<int> b;
    // add all 1 to 2n to b not in a
    int l = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (l < n && a[l] == i) {
            l++;
            continue;
        }
        b.push_back(i);
    }

    // max number alice can win playing optimally
    int alice_max = 0;
    for (int i = n-1; i >= 0; i--) {
        if (b[i] > dq.back()) {
            dq.pop_front();
        } else {
            dq.pop_back();
            alice_max++;
        }
    }

    dq = deque<int>(b.begin(), b.end());
    // max number bob can win playing optimally
    int alice_min = n;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] > dq.back()) {
            dq.pop_front();
        } else {
            dq.pop_back();
            alice_min--;
        }
    }

    cout << alice_min << " " << alice_max << endl;
    return 0;
}