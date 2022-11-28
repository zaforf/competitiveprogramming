#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> ans(n+1);
    for (int i=1;i<min(10,n+1);i++)
        ans[i]=1;
    if (n<10){
        cout<<ans[n];return 0;
    }
    for (int i=10;i<n+1;i++){
        ans[i]=100000000;
        int x = i;
        while (x>0) {
            int dig=x%10;
            ans[i] = min(ans[i],ans[i-dig]+1);
            x/=10;
        }
    }
    cout<<ans[n];
    return 0;
}