#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while (T-->0) {
		int n,q;cin>>n>>q;
		string a,b; cin>>a>>b;
		vector<vector<int>> pre0(n+1,vector<int>(26,0)),pre1(n+1,vector<int>(26,0));

		for (int i=1;i<=n;i++) {
			pre0[i][a[i-1]-'a']++;
			pre1[i][b[i-1]-'a']++;
		}
		for (int i=1;i<=n;i++)
			for (int j=0;j<26;j++) {
				pre0[i][j] += pre0[i-1][j];
				pre1[i][j] += pre1[i-1][j];
			}
		
		for (int i=0;i<q;i++) {
			int ans=0,l,r;cin>>l>>r;
			l--;
			for (int j=0;j<26;j++)
				ans += abs((pre0[r][j]-pre0[l][j])-(pre1[r][j]-pre1[l][j]));
			cout << ans/2 << '\n';
		}
	}
	return 0;
}