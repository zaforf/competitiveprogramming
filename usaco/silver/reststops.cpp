#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int L,N,rf,rb;cin>>L>>N>>rf>>rb;
    vector<pair<long long,long long>> stops(N+1);
    for (long long i=0;i<N;i++)
        cin>>stops[i].first>>stops[i].second;
    stops[N]={0,1000001};
    sort(stops.begin(),stops.end(),greater<pair<long long,long long>>());
    long long maxc = stops[0].second,maxi=0,ans=0;
    for (long long i=1;i<N+1;i++) {
        if (stops[i].second<maxc)
            continue;
        ans += maxc*(stops[maxi].first-stops[i].first)*(rf-rb);
        maxc = stops[i].second;
        maxi = i;
    }
    cout<< ans;
    return 0;
}