#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    long long ret = 0;
    vector<long long> ANS(2 * M + 2, 0);
    vector<int> L(M + 1, 0);
    vector<int> R(M + 1, 0);

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        L[a]++;
        R[b]++;
    }

    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            ANS[i + j] += (long long) L[i] * L[j];
            ANS[i + j + 1] -= (long long) R[i] * R[j];
        }
    }

    for (int i = 0; i < ANS.size()-1; i++) {
        ret += ANS[i];

        cout<<ret<<endl;
    }

    return 0;
}
