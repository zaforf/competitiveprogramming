#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
    vector<int> vals;
    int i = 9;
    while (n>0) {
        vals.push_back(min(n,i));
        n -= i;
        i -= 1;
    }
    sort(vals.begin(),vals.end());
    for (auto n : vals)
        cout << n;
    cout << "\n";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    for (int i;i<n;i++) {
        int inp; cin>>inp; solve(inp);
    }
}