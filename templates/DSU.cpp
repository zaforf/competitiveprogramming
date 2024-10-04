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