#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

#define forn(a, b, c) for (int(a) = (b); (a) < (c); (a)++)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> lprime;
    for (int i=0;i<3001;i++){
        lprime.push_back(i);
    }
    for (int i=2;i<3001;i++) {
        if (lprime[i]!=i)
            continue;
        for (int j=i+i;j<3001;j+=i) {
            lprime[j]=i;
        }
    }
    int n; cin>>n;
    while (n!=0) {
        int ans=n;
        set<int> ps;
        int x = n;
        while (x>1) {
            ps.insert(lprime[x]);
            x/=lprime[x];
        }
        auto a = ps.begin();
        while (a!=ps.end()) {
            ans *= *a-1;
            ans /= *a;
            a++;
        }
        cout<<ans<<"\n";
        cin>>n;
    }
}