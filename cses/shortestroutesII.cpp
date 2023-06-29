#include <bits/stdc++.h>
using namespace std;

long long INF = 1e18;

int main() {
	int N,M,Q;cin>>N>>M>>Q;
	vector<vector<long long>> dist(N,vector<long long>(N, INF));
	for (int i=0;i<M;i++) {
		int a,b,d;cin>>a>>b>>d;a--;b--;
		if (d<dist[a][b])
			dist[a][b] = dist[b][a] = d;
	}

	for (int k=0;k<N;k++)
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				if (dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[j][i]=dist[i][k]+dist[k][j];


	while (Q--) {
		int u,v;cin>>u>>v,u--,v--;
		if (u==v) dist[u][v]=0;
		cout<< (dist[u][v]==INF ? -1 : dist[u][v]) << "\n";
	}
	return 0;
}