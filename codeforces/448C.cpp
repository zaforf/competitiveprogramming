#include <bits/stdc++.h>
using namespace std;

int paint(vector<int>& A, int l, int r) {
    int vert = r - l;
    int hmin = *min_element(A.begin() + l, A.begin() + r);
    for (int i = l; i < r; i++) A[i] -= hmin;
    int x = l, y = l;
    
    if (*max_element(A.begin()+l,A.begin()+r)>0) {
        while (x<r) {
            while (x + 1 < r && A[x] == 0) {x++;y++;}
            while (y + 1 < r && A[y] > 0) y++;
            if (y + 1 == r && A[y] > 0) y++;
            hmin += paint(A, x, y);
            x = ++y;
        }
    }
    return min(vert, hmin);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << paint(A,0,N) << endl;

    return 0;
}