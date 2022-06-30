#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<int> nums;
    for (int i=0;i<10;i++) {
        int n; cin>>n;
        nums.insert(n%42);
    }
    cout<<nums.size();
}