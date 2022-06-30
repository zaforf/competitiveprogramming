#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q; cin>>n>>q;
    bool sieve [n+1] = {false};
    for (int i=2;i<n+1;i++) {
        if (sieve[i])
            continue;
        for (int j=i+i;j<n+1;j+=i) {
            sieve[j] = true;
        }
    }
    sieve[1]=true;
    int cnt;
    for (int i=1;i<n+1;i++) {
        if (!sieve[i])
            cnt+=1;
    }
    cout<<cnt<<endl;
    for (int i=0;i<q;i++) {
        int n; cin>>n;
        n = (sieve[n]) ? 0 : 1;
        cout << n << endl;
    }
}   