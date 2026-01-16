#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n, m, s, t; cin >> n >> m >> s >> t;
    vector<string> grid;
    for (int i=0;i<n;i++) {
        string row; cin >> row;
        row.push_back('0');
        grid.push_back(row);
    }
    vector<vector<int>> rowLen(n, vector<int>(m+1));
    vector<vector<int>> colLen(n, vector<int>(m+1));
    for (int i=0;i<n;i++) {
        if (grid[i][0] == '0') rowLen[i][0] = 0;
        else rowLen[i][0] = 1;
        for (int j=1;j<m;j++) {
            if (grid[i][j] == '0') rowLen[i][j] = 0;
            else rowLen[i][j] = rowLen[i][j-1] + 1;
        }
    }
    for (int j=0;j<m;j++) {
        if (grid[0][j] == '0') colLen[0][j] = 0;
        else colLen[0][j] = 1;
        for (int i=1;i<n;i++) {
            if (grid[i][j] == '0') colLen[i][j] = 0;
            else colLen[i][j] = colLen[i-1][j] + 1;
        }
    }
    vector<array<int,2>> stack;
    auto check = [s,t](int h, int w) {
        return (h >= s && w >= t) || (h >= t && w >= s);
    };
    long long ans = 0;
    for (int i=0;i<n;i++) {
        stack.clear();
        for (int j=0;j<m+1;j++) {
            int cur = j;
            int h = colLen[i][j];
            while (!stack.empty() && stack.back()[1] > h) {
                auto [l, cur_h] = stack.back(); stack.pop_back();

                int cur_w = j - l;
                ans += check(cur_h, cur_w) && (i+1 == n || rowLen[i+1][j-1] < cur_w);
                cur = l;
            }
            if (h > 0 && (stack.empty() || stack.back()[1] < h)) {
                stack.push_back({cur, h});

            }
        }
    }
    cout << ans << endl;



    return 0;
}