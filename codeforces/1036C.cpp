#include <bits/stdc++.h>
using namespace std;

int numdigits(long long n) {
    if (n == 0)
        return 1;

    int digits = 0;
    while (n > 0) {
        digits++;
        n /= 10;
    }
    return digits;
}

int nthdigit(long long num, int n) { return to_string(num)[n]-'0'; }

long long classyupto(long long n) {
	if (n==0) return 0;
	int digits = numdigits(n);
	long long dp[digits][2][4];//digits,digits same as num, # nonzero
	memset(dp,0LL,sizeof(dp));
	dp[0][0][1] = nthdigit(n,0)-1;
	dp[0][0][0] = 1;
	dp[0][1][1] = 1;
	for (int i=1;i<digits;i++)
		for (int j=0;j<2;j++)
			for (int k=0;k<4;k++) {
				if (k==0) {
					dp[i][j][k]=dp[i-1][j][k];
				} else if (j==1) {
					dp[i][1][k]=dp[i-1][1][k-(nthdigit(n,i)==0?0:1)];
				} else {
					dp[i][0][k]=9*dp[i-1][0][k-1]+max((nthdigit(n,i)-1),0)*dp[i-1][1][k-1]+min(1,nthdigit(n,i))*(dp[i-1][1][k])+dp[i-1][0][k];
				}
			}
	long long ret = 0;
	// for (auto a : dp[digits-1][0])
	// 	cout<<a<<" ";
	// cout<<"\n";
	// for (auto a : dp[digits-1][1])
	// 	cout<<a<<" ";
	// cout<<"\n";
	for (int j=0;j<2;j++)
		for (int k=1;k<4;k++) {
			ret = ret + dp[digits-1][j][k];
		}
	return ret;
}

int32_t main() {
	int T; cin>>T;
	while (T--) {
		long long a,b;cin>>a>>b;
		cout<<classyupto(b)-classyupto(a-1)<<"\n";
	}
	return 0;

}