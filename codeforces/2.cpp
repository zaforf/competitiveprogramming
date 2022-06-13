#include <bits/stdc++.h>
#define l long long
const l M = 1e9 + 7;

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for (int i=0;i<n;i++) {
        int a; cin>>a;
        if (a==1) {
            int inp; cin >> inp;
            cout << "-1"<<"\n";
            continue;
        }
        set<int> nums;
        vector<int> order;
        for (int i=0;i<a;i++) {
            int inp; cin>>inp; nums.insert(inp); order.push_back(inp);
        }
        for (int i=0;i<a-2;i++) {
            auto x = nums.begin();
            if (*x==order[i]) {
                cout <<*(++x)<< " ";
                nums.erase(x);
            }
            else {
                cout << *x << " ";
                nums.erase(x);
            }
        }
        auto x = (nums.begin());
        x++;
        if (*x==order[order.size()-1]) {
            cout << *x << " " << *nums.begin() << "\n";
        }
        else {
            x--;
            cout << *x << " " << *(--nums.end()) << "\n";
        }
    }
}   