#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i=0;i<n;i++) {
        int a,b; cin >> a >> b;
        l sum =0;
        multiset<int> ints;
        for (int i=0;i<a;i++) {
            int inp; cin>>inp; ints.insert(inp%b);
            sum +=inp;
        }
        int ans = 0;
        while (ints.size()>0){
            int check = *(--ints.end());
            auto a = ints.lower_bound(b-check);
            if (a==ints.end()) {
                ans += (*ints.begin()+check)%b;
                ints.erase(ints.begin());
                ints.erase(--ints.end());
            }
            else {
                ans += (*a + check)%b;
                ints.erase(a);
                ints.erase(--ints.end());
            }
        }
        cout << (sum-ans)/b << "\n";
    }
}