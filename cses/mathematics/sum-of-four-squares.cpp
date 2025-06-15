#include <bits/stdc++.h>
using namespace std;

vector<int> squares(10000001, -1);

int main() {
    int T;cin>>T;
    set<pair<int,int>> nums;
    for (int i = 0; i < T; ++i) {
        int x; cin >> x;
        nums.insert({x, i});
    }
    int MAXN = (*nums.rbegin()).first;

    vector<array<int, 4>> ans(T);
    
    for (int i = 0; i * i <= MAXN; ++i) {
        for (int j = 0; i*i + j*j <= MAXN; ++j) {
            squares[i * i + j * j] = i;
            auto it = nums.begin();
            while (it != nums.end()) {
                auto& [goal, ind] = *it;
                int sub = goal - (i * i + j * j);
                if (0 <= sub && sub <= MAXN && squares[sub] != -1) {
                    int k = squares[sub];
                    ans[ind] = {i, j, k, (int) sqrt(sub - k * k)};
                    it = nums.erase(it);
                } else it++;
            }
            if (nums.size() == 0) break;
        }
        if (nums.size() == 0) break;
    }

    for (auto& list : ans) {
        cout << list[0] << " " << list[1] << " " << list[2] << " " << list[3] << endl;
    }



    return 0;
}