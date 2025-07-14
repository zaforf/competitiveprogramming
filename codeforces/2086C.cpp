#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

vector<int> e(MAXN,-1);

int get(int x) { return (e[x]<0 ? x : e[x]=get(e[x])); }

int merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a==b) return 0;
    if (e[a]>e[b]) swap(a,b);
    e[a] += e[b];
    e[b] = a;
    return 1;
}

int sz(int x) {return -e[get(x)];}

void solve() {
    int n; cin>>n;
    for (int i = 0; i <= n; ++i) e[i] = -1;
    vector<int> p(n), d(n);
    for (int& i : p) cin>>i;
    for (int& i : d) cin>>i;
    int c = 0;
    vector<int> vis(n);
    for (int i=0;i<n;++i) {
        c = i;
        if (!vis[c])
        while (!vis[c]) {
            merge(c, p[c] - 1);
            vis[c] = 1;
            c = p[c] - 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[get(d[i]-1)] < 2) {
            ans += sz(d[i]-1);
            vis[get(d[i]-1)] = 2;
        }
        cout << ans << " ";
    }
    cout << endl;

}

int main() {
    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}