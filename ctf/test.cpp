#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int it = 1000;
using uid = uniform_int_distribution<int>;

double test(vector<int>& x) {
    int cnt = 0;
    for (int i = 0; i < it; i++) {
        vector<int> a(8);
        int cur = uid(1,8)(rng);
        for (int j = 0; j < 8; j++) {
            a[j] = cur;
            if (cur == 1) cur++;
            else if (cur == 8) cur--;
            else cur = cur - 1 + 2 * uid(0,1)(rng);
        }
        for (int j = 0; j < 8; j++) {
            if (x[j] == a[j]) {
                cnt++; break;
            }
        }
    }
    return (double)cnt/it;

}

int main() {
    for (int i = 0; i < (1<<24); i++) {
        vector<int> x;
        for (int j = 0; j < 8; j++) {
            x.push_back((i>>(3*j))%8+1);
        }
        double y = test(x);
        if (y > 0.89) {
            for (int i : x) cout << i << " ";
            cout << y << "\n";
        }
    }
    return 0;
}
