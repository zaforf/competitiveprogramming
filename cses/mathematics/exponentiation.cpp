#include <iostream>
 
using namespace std;
 
int main()
{
    int n; cin >> n;
    for (int i=0;i<n;i++){
        long long a,b,ans=1; cin>>a>>b;
        while (b) {
            if(b&1){
                ans*=a;
                ans%=1000000007;
            }
            a*=a;
            a%=1000000007;
            b>>=1;
        }
        cout << ans << "\n";
    }
    
}