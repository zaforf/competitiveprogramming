#include <bits/stdc++.h>
using namespace std;

int apply(int S, int R, int A) {
	S ^= S&R;
	S |= A;
	return S;
}

void solve() {
	int N,M;cin>>N>>M;
	vector<int> dist(1024,1<<30);
	vector<bool> vis(1024,false);
	string start; cin>>start;
	dist[stoi(start,0,2)]=0;
	vector<vector<int>> edges(M,vector<int>(3));
	for (int i=0;i<M;i++) {
		int W;cin>>W;
		string X; cin>>X;
		string Y; cin>>Y;
		edges[i][0]=W;
		edges[i][1]=stoi(X,0,2);
		edges[i][2]=stoi(Y,0,2);
	}
	for (int i=0;i<1024;i++) {
		int v=-1;
		for (int j=0;j<1024;j++)
			if(!vis[j] && (v==-1 || dist[j]<dist[v]))
				v = j;
		if (dist[v]==1<<30)
			break;
		vis[v]=true;
		for (auto edge : edges) {
			int x = apply(v,edge[1],edge[2]);
			dist[x]=min(dist[x],dist[v]+edge[0]);
		}
	}
	cout<<(dist[0]==1<<30?-1:dist[0])<<"\n";
}

int main() {
	int T;cin>>T;
	while (T--) solve();
	return 0;
}