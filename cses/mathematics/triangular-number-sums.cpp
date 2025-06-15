#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;

    while (T --> 0) {
        int n; cin >> n;
        bool done = false;

        for (int i=0; i*(i+1)/2 <= n; i++) {
            int c = -2 * (n - (i*(i+1)/2));
            int b = 1;
            int det = b*b - 4*c;
            if (det < 0) continue;
            int sq = sqrt(det);
            if (sq * sq != det) continue;
            int x = -b + sq;
            if (x % 2 != 0) continue;
            x /= 2;
            if (i*(i+1)/2 + x*(x+1)/2 == n) {
                if (i == 0) {
                    cout << 1 << '\n';
                    done = true;
                } else {
                    cout << 2 << '\n';
                    done = true;
                }
                break;
            }
        }
        if (!done) {
            cout << 3 << '\n';
        }



    
    }


    
    return 0;
}