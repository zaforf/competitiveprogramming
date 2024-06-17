#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+1;
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
	int n,m,largest=1;cin>>n>>m;
	for (int i=0;i<m;i++) {
		int a,b;cin>>a>>b;
		if (merge(a,b)) n--;
		largest = max(largest,sz(a));
		cout << n << " " << largest << endl;
	}
	return 0;
}