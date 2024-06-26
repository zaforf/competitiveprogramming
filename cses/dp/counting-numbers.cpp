#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> diga,digb;
int dp[10][2][19][2];

int solve(int x, bool at_max, int i, bool started, vector<int> &digs) {
	if (dp[x][at_max][i][started]!=-1) return dp[x][at_max][i][started];
	// last digit, if at max, digits left
	if (i==digs.size()-1) return 1;
	int ret=0;
	if (at_max) {
		for (int j=digs[i+1];j>=0;j--)
			if (j==x) continue;
			else ret += solve(j,j==digs[i+1],i+1,true,digs);
	} else {
		for (int j=9;j>=0;j--)
			if (started && j==x) continue;
			else ret += solve(j,false,i+1,started | (j!=0),digs);
	}
	dp[x][at_max][i][started]=ret;
	return ret;
}

int32_t main() {
	int a,b,ans=0;cin>>a>>b;
	if (b==0) ans++;
	if (a==1) ans--;
	a--;
	while (b>0) { digb.push_back(b%10);b/=10;}
	while (a>0) { diga.push_back(a%10);a/=10;}
	reverse(digb.begin(),digb.end());
	reverse(diga.begin(),diga.end());
	memset(dp,-1ll,sizeof(dp));
	if (digb.size())
		for (int i=digb[0];i>=0;i--)
			ans += solve(i,i==digb[0],0,i!=0,digb);
	memset(dp,-1ll,sizeof(dp));
	if (diga.size())
		for (int i=diga[0];i>=0;i--)
			ans -= solve(i,i==diga[0],0,i!=0,diga);
	cout << ans;
	return 0;
}