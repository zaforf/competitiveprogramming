#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

vector<vector<pii>> adj(64);
int nbrs[64];
int ans[64];
int k=1;

vector<pii> neighbors(int x, int y) {
	vector<pii> ret;
	if (x-1>=0 && y-2>=0) ret.push_back({x-1,y-2});
	if (x-2>=0 && y-1>=0) ret.push_back({x-2,y-1});
	if (x-2>=0 && y+1<8) ret.push_back({x-2,y+1});
	if (x-1>=0 && y+2<8) ret.push_back({x-1,y+2});
	if (x+1<8 && y+2<8) ret.push_back({x+1,y+2});
	if (x+2<8 && y+1<8) ret.push_back({x+2,y+1});
	if (x+2<8 && y-1>=0) ret.push_back({x+2,y-1});
	if (x+1<8 && y-2>=0) ret.push_back({x+1,y-2});
	return ret;
}

void dfs(int x, int y) {
	ans[8*x+y]=k++;
	pii pmin; int nbmin=10;
	for (pii nb : adj[8*x+y]) {
		nbrs[8*nb.f+nb.s]--;
		if (ans[8*nb.f+nb.s]==0 && nbrs[8*nb.f+nb.s]<nbmin) {
			nbmin = nbrs[8*nb.f+nb.s];
			pmin = nb;
		}
	}
	if (nbmin!=10)
		dfs(pmin.f,pmin.s);
}

int main() {
	int x,y;cin>>x>>y;x--;y--;
	for (int i=0;i<8;i++)
		for (int j=0;j<8;j++) {
			adj[8*i+j] = neighbors(i,j);
			nbrs[8*i+j] = adj[8*i+j].size();
		}
	dfs(y,x);
	for (int i=0;i<8;i++) {
		for (int j=0;j<8;j++)
			cout << ans[8*i+j] << " ";
		cout << endl;
	}
	return 0;
}