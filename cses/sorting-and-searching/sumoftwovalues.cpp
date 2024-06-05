#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,targ;cin>>N>>targ;
    vector<pair<int,int>> vals(N);
    for (int i=0;i<N;i++) {
        cin>>vals[i].first;
        vals[i].second=i;
    }
    sort(vals.begin(),vals.end());
    int l=0,r=N-1;
    // for (auto a : vals)
    //     cout << a.first << " ";
    // cout<<"\n";
    while (l<r) {
        int sum = vals[l].first+vals[r].first;
        if (sum==targ) {
            cout<<vals[l].second+1<<" "<<vals[r].second+1;
            break;
        } else if (sum>targ)
            r--;
        else
            l++;
    }
    if (l==r)
        cout<<"IMPOSSIBLE";
    return 0;
}