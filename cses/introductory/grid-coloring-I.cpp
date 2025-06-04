#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    for (string& s : grid) cin>>s;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            char c = (i&1) == (j&1) ? 'A' : 'B';
            if (c==grid[i][j]) c += 2;
            cout << c;
        }
        cout<<endl;
    }
    return 0;
}