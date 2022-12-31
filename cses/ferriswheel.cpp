#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

int main() {
    multiset<int> carts;
    int n,k;cin>>n>>k;
    int cnt=0;
    vector<int> vals(n);
    for (int i=0;i<n;i++)
        cin>>vals[i];
    sort(all(vals),greater<int>());
    for (int i=0;i<n;i++) {
        if (carts.size()==0 || k<*carts.begin()+vals[i])
            carts.insert(vals[i]);
        else {
            cnt +=1;
            carts.erase(carts.begin());
        }
    }
    cout<<carts.size()+cnt;
    return 0;
}