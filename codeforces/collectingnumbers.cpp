#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n;cin>>n;
    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        int inp;cin>>inp;nums[inp-1]=i;
    }
    int ans=1;
    for (int i=1;i<n;i++)
        if (nums[i]<nums[i-1])
            ans++;
    cout<<ans;
    return 0;
}