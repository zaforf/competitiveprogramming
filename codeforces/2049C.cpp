#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,x,y; cin>>n>>x>>y; x--, y--;
    vector<int> ans(n);
    if (n % 2 == 0) {
        for (int i=0;i<n;i++)
            ans[i] = i & 1;
        if (ans[x] == ans[y])
            ans[x] = 2;
    } else {
        for (int i=0;i<n;i++)
            ans[i] = i % 3;
        if (ans[n-1] == ans[0]) {
            ans[n-1] = 1;
            ans[n-2] = 0;
        }
        if (ans[x] == ans[y]) {
            set<int> in;
            in.insert(ans[(x-1+n)%n]);
            in.insert(ans[(x+1)%n]);
            in.insert(ans[y]);
            int mex = 0;
            while (in.count(mex)) mex++;
            ans[x] = mex;
        }
    }
    for (int a : ans) cout << a << " ";
        cout << endl;
    
}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}