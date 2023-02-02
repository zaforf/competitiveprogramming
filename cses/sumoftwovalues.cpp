#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    unordered_map<int,int> nums;
    int n,targ;cin>>n>>targ;
    for (int i=0;i<n;i++) {
        int inp;cin>>inp;
        if (nums.count(targ-inp)) {
            cout<<nums[targ-inp]+1<<" "<<i+1;
            return 0;
        }
        nums[inp]=i;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}