#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	while (T--) {
		int N;cin>>N;
		vector<int> vals(N);
		for (int& v : vals) cin>>v;
		vector<vector<int>> after(N,vector<int>(N+1,0)); // index, num
		after[N-1][vals.back()]++;
		for (int i=N-2;i>=0;i--)
			for (int j=0;j<N+1;j++)
				after[i][j]=after[i+1][j]+(vals[i]==j?1:0);

		vector<vector<int>> before(N,vector<int>(N+1,0)); // index, num
		before[0][vals.front()]++;
		for (int i=1;i<N;i++)
			for (int j=0;j<N+1;j++)
				before[i][j]=before[i-1][j]+(vals[i]==j?1:0);

		long long ans=0;
		for (int j=1;j<N;j++)
			for (int k=j+1;k+1<N;k++)
					ans+=before[j-1][vals[k]]*after[k+1][vals[j]];
		cout<<ans<<"\n";

	}
	return 0;
}