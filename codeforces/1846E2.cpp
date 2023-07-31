#include <bits/stdc++.h>
using namespace std;

long long val(long long k, int it) {
    long long sum = 1, curr = 1; it--;
    for (int i = 0; i < it; i++) {
        curr *= k;
        sum += curr;
    }
    return sum;
}

int findtrue(long long l, long long r, int d, long long Q) {
    r++;
    while (l < r) {
        long long m = (l + r) / 2;
        if (pow(m,d-1)>Q) {r=m;continue;}
        long long x = val(m,d);
        if (x>=Q) {
            if (x==Q) {
                return m;
            }
            else {
                r = m;
            }
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long Q;
        cin >> Q;
        for (int j = 3; j < 65; j++) {
            int s = findtrue(2, pow(Q,(double)1/(j-1))+1, j, Q);
            if (s != -1) {
                cout << "YES" << endl;
                break;
            }
            else if (j == 64)
                cout << "NO" << endl;
        }
    }

    return 0;
}
