#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 1;

int main() {
    vector<vector<int>> pos(N);
    int n = 0;
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin>>t;
        if (t == 1) {
            int x;
            cin >> x;
            pos[x].push_back(n);
            n++;
        } else {
            int x, y;
            cin >> x >> y;
            if (x != y) {
                if (pos[x].size() > pos[y].size())
                    pos[x].swap(pos[y]);
                for (int i : pos[x])
                    pos[y].push_back(i);
                pos[x].clear();
            }
        }
    }

    vector<int> ans(n);
    for (int x = 0; x < N; ++x) {
        for (int i : pos[x])
            ans[i] = x;
    }

    for (int x : ans)
        cout << x << ' ';
    cout << '\n';

    return 0;
}