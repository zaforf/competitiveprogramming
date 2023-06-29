#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
vector<int> e(MAXN,-1);

int get(int x) { return (e[x]<0 ? x : e[x]=get(e[x])); }

bool merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a==b) return false;
	if (e[a]>e[b]) swap(a,b);
	e[a] += e[b];
	e[b] = a;
	return true;
}

int sz(int x) {return -e[get(x)];}

int main() {
	int N;cin>>N;
	vector<pair<int,int>> badpairs;
	for (int i=0;i<N-1;i++) {
		int a,b;cin>>a>>b;
		if (!merge(a,b))
			badpairs.push_back({a,b});
	}
	vector<int> heads;
	for (int i=1;i<N+1;i++)
		if (e[i]<0)
			heads.push_back(i);
	cout<<badpairs.size()<<"\n";
	int x=0;
	for (int j=1;j<heads.size();j++,x++)
		cout<<badpairs[x].first<<" "<<badpairs[x].second<<" "<<heads[0]<<" "<<heads[j]<<"\n";
	return 0;
}