#include <bits/stdc++.h>
using namespace std;

const int MAXX = 1000001;
int sieve[MAXX];



void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++) a[i] = i+1;
    for (int i=n/2;i>1;i--) {
        if (sieve[i]) continue;
        int p = i;
        for (int j=i+i;j<=n;j+=i) {
            if (a[j-1] % i == 0) {
                swap(a[i-1], a[j-1]);
                p = j;
            }
        }
    }
    for (int x : a)
        cout << x << " ";
    cout << endl;
}

int main() {
    for (int i=2;i<MAXX;i++)
        if (!sieve[i])
            for (int j=2*i;j<MAXX;j+=i)
                sieve[j]=i;

    int T;cin>>T;
    while (T --> 0) {
        solve();
    }
    return 0;
}