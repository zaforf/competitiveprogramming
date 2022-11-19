#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,d;cin>>n>>d;
    vector<int> coins(n);
    for (int i=0;i<n;i++)
        cin>>coins[i];
    vector<long long> ans(d+1);
    for (auto c : coins) {
        if (c<d+1)
            ans[c] += 1;
        for (int i=1;i<d+1;i++) {
            if (ans[i]>0 && i+c<d+1) {
                ans[i+c] += ans[i];
                ans[i+c] %= 1000000007;
            }
        }
    }
    cout<<ans[d];
    
}