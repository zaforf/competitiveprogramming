#include <bits/stdc++.h>
using namespace std;

vector<int> vals;
int N,K;

bool f(long long x) {
    long long csum=0,cnt=0;
    for (int i=0;i<N;i++) {
        if (csum+vals[i]<=x)
            csum+=vals[i];
        else if (vals[i]<=x) {
            cnt++;csum=vals[i];
        }
        else
            return false;
    }
    cnt++;
    return (cnt<=K);
}

long long binlowesttrue(long long l,long long h) {
    l--;
    while (l<h) {
        long long med = (l+h)/2;
        if (f(med))
            h = med;
        else
            l = med+1;
    }
    return l;
}

int main() {
    // freopen("std.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    cin>>N>>K; vals.resize(N);
    for (int i=0;i<N;i++)
        cin>>vals[i];
    cout<<binlowesttrue(0,1000000000000000);
    return 0;
}