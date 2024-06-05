#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()

int main() {
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    int n;cin>>n;
    vector<int> nums(n);
    for (int & a : nums){cin>>a;}
    sort(all(nums));
    long long ans=0;
    // range starts at 0-0
    for (int & a : nums) {
        if (ans+1<a) // if range 0-currsum, then currsum+1 might be
            break; // too little to be covered by 0+a-currsum+a, so ans+1 is ans
        ans+=a;
    }
    cout<<++ans;
    return 0;
}