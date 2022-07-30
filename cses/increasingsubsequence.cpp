#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> process;
    for (int i=0;i<n;i++) {
        int inp; cin >> inp;
        auto check = lower_bound(process.begin(),process.end(),inp);
        if (check==process.end())
            process.push_back(inp);
        else
            process[check-process.begin()] = inp;
    }
    cout << process.size();
}