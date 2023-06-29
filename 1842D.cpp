#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> ans;
bool vis[101];
long long MAXT = LLONG_MAX;
int N;

void floydwarshall() {
	for (int k=1;k<=N;k++)
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++) {
				ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
			}
}

int main() {
	int M;cin>>N>>M;
	ans.resize(N+1,vector<long long>(N+1,1e18));
	for (int i=0;i<M;i++) {
		long long a,b,w;cin>>a>>b>>w;
		ans[a][b] = ans[b][a] = min(ans[a][b],w);
	}
	for (int i=1;i<=N;i++) ans[i][i]=0;
	floydwarshall();
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			ans[i][j]=min(ans[i][j],ans[N][1]);
	if (ans[N][1]==1e18)
		cout<<"inf";
	else {
		set<long long> s;
		for (int i=1;i<=N;i++)
			if (ans[N][i]!=0 && ans[N][i]!=1e18)
				s.insert(ans[N][i]);
		cout<<ans[N][1]<<" "<<s.size()<<"\n";
		vector<bool> print(N);
		for (int i=1;i<=N;i++)
			if (ans[N][i]==1e18)
				ans[N][i]=0;
		while (ans[N][1]) {
			long long mint = 1e18;
			for (int i=1;i<=N;i++) {
				if (ans[N][i]==0) continue;
				mint = min(mint,ans[N][i]);
				print[i-1]=true;
			}
			for (int i=0;i<N;i++)
				cout<<print[i];
			cout<<" "<<mint<<"\n";
			for (int i=1;i<=N;i++) {
				ans[N][i]=max(ans[N][i]-mint,0LL);
				print[i-1]=false;
			}
		}

	}
	return 0;
}