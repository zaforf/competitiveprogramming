#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    freopen("watering_well_chapter_1_input.txt", "r", stdin);
	freopen("well.txt", "w", stdout);
    int T; cin>>T;
    for (int i=0;i<T;i++) {
        ll ans=0;
        vector<ll> x(3001,0);
        vector<ll> y(3001,0);
        int p; cin>>p;
        vector<int> xs(p); vector<int> ys(p);
        for (int j=0;j<p;j++)
            cin>>xs[j]>>ys[j];
        for (int k=0;k<3001;k++){ 
            for (int xv : xs) {
                x[k] += (xv-k)*(xv-k);
                x[k] %= 1000000007;
            }
            for (int yv : ys) {
                y[k] += (yv-k)*(yv-k);
                y[k] %= 1000000007;
            }
        }
        cin>>p;
        for (int j=0;j<p;j++) {
            int a,b; cin>>a>>b;
            ans+=x[a]+y[b];
            ans%=1000000007;
        }
        cout<<"Case #"<<i+1<<": "<<ans<<"\n";
    }

}