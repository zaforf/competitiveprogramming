#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;
int e[MAXN],NEXIST=0;
bool exists[MAXN];

int get(int a) { return e[a]<0 ? a : e[a] = get(e[a]); }

bool merge(int a,int b) {
	a = get(a), b = get(b);
	if (a==b) return false;
	if (e[a] > e[b]) swap(a,b);
	e[a] += e[b];
	e[b] = a;
	return true;
}

int sz(int a) { return - e[get(a)]; }

int main() {
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	int N,M;cin>>N>>M;
	vector<vector<int>> adj(N+1);
	for (int i=0;i<M;i++) {
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> ord(N);
	vector<string> ans;
	for (int i=0;i<N;i++) {
		cin>>ord[i];
		e[i+1]=-1;
	}
	reverse(begin(ord),end(ord));
	for (int i=0;i<N;i++) {
		NEXIST++;exists[ord[i]]=true;
		for (int nb : adj[ord[i]])
			if (exists[nb]) 
				merge(nb,ord[i]);
		ans.push_back( (sz(ord[i])==NEXIST ? "YES" : "NO") );
	}
	reverse(begin(ans),end(ans));
	for (auto a : ans)
		cout<<a<<"\n";
	return 0;
}
