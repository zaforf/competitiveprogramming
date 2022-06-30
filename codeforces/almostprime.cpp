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
    int n,ans=0; cin>>n;
    forn(i,1,n+1) {
        set<int> ps;
        int x = i;
        while (x>1) {
            if (ps.size()>2)
                break;
            ps.insert(lprime[x]);
            x/=lprime[x];
        }
        if (ps.size()==2)
            ans++;
    }
    cout<<ans;
}