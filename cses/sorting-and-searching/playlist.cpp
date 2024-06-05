#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> pls(n);
    for (int i=0;i<n;i++)
        cin>>pls[i];
    set<int> win;
    int l=0,r=0,ans=0;
    for (;r<n;) {
        while (r<n&&!win.count(pls[r])) {
            win.insert(pls[r]);
            r++;
        }
        ans=max(ans,r-l);
        win.erase(pls[l]);
        while (pls[l]!=pls[r]) {
            l++;
            win.erase(pls[l]);
        }
        l++;
    }
    cout<<ans;
    return 0;
}