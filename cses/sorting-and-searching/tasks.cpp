#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<vector<int> > nums(n, vector<int>(2));
    for (int i=0;i<n;i++){
        cin>>nums[i][0]>>nums[i][1];
    }
    sort(nums.begin(),nums.end());
    long long t=0,ans=0;
    for (int i=0;i<n;i++){
        t+=nums[i][0];
        ans+=nums[i][1]-t;
    }
    cout<<ans;
    return 0;
}