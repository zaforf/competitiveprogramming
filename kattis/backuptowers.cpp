#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int r, c; cin >> r >> c;
    int n; cin >> n;
    vector<array<int,2>> towers(n);
    for (auto &[x, y] : towers) cin >> x >> y, --x, --y;
    queue<array<int,3>> q; // {tower index, x, y}
    
    for (int i = 0; i < n; ++i) {
        auto [x, y] = towers[i];
        q.push({i, x, y});
    }
    vector<vector<array<int,2>>> nearest(r, vector<array<int,2>>(c, {-1, -1}));
    vector<vector<array<int,2>>> dist(r, vector<array<int,2>>(c, {INT_MAX, INT_MAX}));
    // stores the first and second nearest towers for each cell
    int d = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int j=0;j<sz;j++) {
            auto [i, x, y] = q.front(); q.pop();

            // if same distance, take the smaller tower index
            // otherwise store nearest and second nearest
            // they cannot be the same
            if (dist[x][y][0] > d) {
                dist[x][y][1] = dist[x][y][0];
                nearest[x][y][1] = nearest[x][y][0];
                dist[x][y][0] = d;
                nearest[x][y][0] = i;
            } else if (dist[x][y][0] == d && nearest[x][y][0] > i) {
                dist[x][y][1] = dist[x][y][0];
                nearest[x][y][1] = nearest[x][y][0];
                nearest[x][y][0] = i;
            } else if (dist[x][y][1] > d && nearest[x][y][0] != i) {
                dist[x][y][1] = d;
                nearest[x][y][1] = i;
            } else if (dist[x][y][1] == d && nearest[x][y][1] > i && nearest[x][y][0] != i) {
                nearest[x][y][1] = i;
            } else {
                continue; // no need to explore further
            }

            



            for (auto [dx, dy] : vector<array<int,2>>{{1,0},{-1,0},{0,1},{0,-1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && dist[nx][ny][1] >= d) {
                    
                    q.push({i, nx, ny});
                }
            }
        }
        d++;

    }

    // prints the first grid
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << nearest[i][j][0] + 1 << " ";
        }
        cout << endl;
    }
    // prints the second grid
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << nearest[i][j][1] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}