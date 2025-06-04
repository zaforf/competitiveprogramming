#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> grid;
    for (int i = 0; i < n; ++i) {
        string row; cin >> row;
        grid.push_back(row);
    }
    char min_char = grid[0][0], next_min = 'Z';
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    q.push({0, 0});
    string ans = "";

    while (!q.empty()) {
        ans += min_char;
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto [x, y] = q.front(); q.pop();
            if (grid[x][y] != min_char)
                continue;
            if (x + 1 < n && !visited[x + 1][y]) {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
                next_min = min(next_min, grid[x + 1][y]);
            }
            if (y + 1 < n && !visited[x][y + 1]) {
                visited[x][y + 1] = true;
                q.push({x, y + 1});
                next_min = min(next_min, grid[x][y + 1]);
            }
        }
        min_char = next_min;
        next_min = 'Z';
    }
    cout << ans << endl;

    return 0;
}