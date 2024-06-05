#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<int> e(MAXN,-1);

int get(int x) { return (e[x]<0 ? x : get(e[x])); }

int merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a==b) return false;
	if (e[a] > e[b]) swap(a,b);
	e[a] += e[b];
	e[b] = a;
	return true;
}

int sz(int x) { return -e[get(x)]; }

int main() {
	int N,M;cin>>N>>M;
	vector<pair<long long,pair<int,int>>> edges;
	for (int i=0;i<M;i++) {
		int a,b,w;cin>>a>>b>>w;
		edges.push_back({w,{a,b}});
	}
	sort(begin(edges),end(edges));
	long long ans=0;
	for (int i=0;i<M;i++) {
		if (merge(edges[i].second.first,edges[i].second.second)) { 
			ans += edges[i].first;
		}
	}
	if (sz(1)==N)
		cout<<ans;
	else
		cout<<"IMPOSSIBLE";
	return 0;
}