#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;


/*
from sortedcontainers import SortedSet

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    unhandled = SortedSet()
    min_so_far = 1e9
    edges = []
    for v in a:
        while unhandled and unhandled[0] < v:
            pair = unhandled.pop(0)
            edges.append((pair, v))

        if min_so_far < v:
            edges.append((min_so_far, v))
        elif v != 1:
            unhandled.add(v)

    if unhandled:
        print("NO")
    else:
        print("YES")
        for u, v in edges:
            print(u, v)
*/


void solve() {
    int n; cin>>n;
    vecin(a, n);
    set<int> unhandled;
    int min_so_far = 1e9;
    vector<pair<int,int>> edges;
    for (auto v : a) {
        while (!unhandled.empty() && *unhandled.begin() < v) {
            int pair = *unhandled.begin();
            unhandled.erase(unhandled.begin());
            edges.emplace_back(pair, v);
        }

        if (min_so_far < v) {
            edges.emplace_back(min_so_far, v);
            min_so_far = min(min_so_far, v);
        } else if (v != 1) {
            unhandled.insert(v);
        }
    }
    if (!unhandled.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (auto [u, v] : edges) {
            cout << u << " " << v << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}