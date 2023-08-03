#include <bits/stdc++.h>
#include <array>
using namespace std;

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int N,ans=0,t=0;cin>>N;
    vector<array<int,3>> order;
    set<pair<int, pair<int, int>>> seniorpq;
    for (int i=0;i<N;i++) {
        int a,b;cin>>a>>b;
        order.push_back({a,b,i});
    }
    sort(order.begin(),order.end());
    // for (auto a : order) cout<<a[0]<<" ";
    // cout<<endl;
    int i=0;
    while (i<N) {
        // cout<<i<<" "<<t<<endl;
        if (t<order[i][0]) {
            t=order[i][0];
            t += order[i][1];
            i++;
        }
        while (i<N && order[i][0]<t) {
            // cout << "pushed "<<i<<endl;
            seniorpq.insert({order[i][2], {order[i][1], order[i][0]}});
            i++;
        }
        while (!seniorpq.empty()) {
            ans = max(ans,t-seniorpq.begin()->second.second);
            t += seniorpq.begin()->second.first;
            seniorpq.erase(seniorpq.begin());
            while (i<N && order[i][0]<t) {
                // cout << "pushed "<<i<<endl;
                seniorpq.insert({order[i][2], {order[i][1], order[i][0]}});
                i++;
            }
        }
        // cout<<"processed up to "<<i<<" ans is now "<<ans << endl;
        // cout << "time is "<<t << endl;
    }
    cout<<ans<<"\n";
    return 0;
}
