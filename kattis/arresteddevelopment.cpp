#include <bits/stdc++.h>
using namespace std;

#define vecin(name, len) vector<int> name(len); for (auto &_ : name) cin >> _;
#define vecout(v) for (auto _ : v) cout << _ << " "; cout << endl;

int main() {
    int n; cin>>n;
    vector<array<int,2>> ps(n);
    for(int i=0;i<n;i++) cin>>ps[i][0]>>ps[i][1];
    vector<int> dp(5000001,-1); // dp[i] = the minimum b can take given a took i
    dp[0]=0;
    for(int i=0;i<n;i++){
        int a=ps[i][0],b=ps[i][1];
        for(int j=5000000;j>=0;j--){
            if(dp[j]!=-1){
                // take a
                if (j+a<=5000000)
                    dp[j+a] = min(dp[j+a]==-1?INT_MAX:dp[j+a], dp[j]);
                // take b
                dp[j] += b;
            }
        }
    }

    int ans=INT_MAX;
    for(int i=0;i<=5000000;i++){
        if(dp[i]!=-1){
            ans=min(ans,max(i,dp[i]));
        }
    }
    cout<<ans<<endl;

    return 0;
}