#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int N;cin>>N;
    vector<bool> Bcards(2*N,1);
    vector<int> game(N);
    for (int i=0;i<N;i++) {
        cin>>game[i];Bcards[game[i]-1]=false;
    }
    set<int> fhalf,shalf;
    for (int i=0;i<2*N;i++) {
        if (Bcards[i] && shalf.size()<N/2)
            shalf.insert(i+1);
        else if (Bcards[i])
            fhalf.insert(i+1);
    }
    int ans=0;
    for (int i=0;i<N;i++) {
        if (i<N/2 && fhalf.lower_bound(game[i])!=fhalf.end()) {
            ans++;
            fhalf.erase(fhalf.lower_bound(game[i]));
        }
        else if (i>=N/2 && shalf.lower_bound(game[i])!=shalf.begin()) {
            ans++;
            shalf.erase(--shalf.lower_bound(game[i]));
        }
    }
    cout<<ans;
    return 0;
}