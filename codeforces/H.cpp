#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> good(n, vector<bool>(m, false));
    vector<string> rows(n);

    for (int i = 0; i < n; i++) {
        cin >> rows[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (rows[i][j] == 'B') {
                good[i][j] = true;
            } else {
                bool canMoveToLosing = false;
                if (i + 1 < n && !good[i + 1][j]) canMoveToLosing = true;
                if (j + 1 < m && !good[i][j + 1]) canMoveToLosing = true;
                if (i + 1 < n && j + 1 < m && !good[i + 1][j + 1]) canMoveToLosing = true;
                good[i][j] = canMoveToLosing;
            }
        }
    }
    if (good[0][0]) {
        cout << "Alice";
    } else {
        cout << "Bob";
    }

    return 0;
}
