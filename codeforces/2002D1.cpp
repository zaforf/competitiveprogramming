#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int n, vector<int>& ord) {
	if (node>n) return;
	ord.push_back(node);
	dfs(2*node,n,ord);
	dfs(2*node+1,n,ord);
}

void solve() {
	int n,q,t; cin>>n>>q;
	for (int i=0;i<n-1;i++) cin>>t;

	vector<int> ord;
	dfs(1,n,ord);
	vector<int> perm(n), par(n,0);

	vector<int> ind(n+1,0);
	for (int i=1;i<n;i++) {
		ind[ord[i]]=i;
		par[i] = ind[ord[i]/2];
	}
	vector<vector<int>> kids(n);
	for (int i=1;i<n;i++) {
		kids[par[i]].push_back(i);
	}

	for (int& p : perm) cin>>p;

	vector<bool> wrong(n,false);
	int bad = 0;
	auto check = [&](int i) {
		return (par[i]==0 && perm[i]==1 || perm[par[i]]==perm[i]/2);
	};

	wrong[0] = !check(0);
	if (wrong[0]) bad++;
	for (int i=1;i<n;i++) {
		wrong[i] = !check(i);
		bad += wrong[i];
	}
	int a,b;
	unordered_set<int> upd;
	for (int i=0;i<q;i++) {
		cin>>a>>b;a--;b--;
		upd.clear();
		upd.insert(a);upd.insert(b);
		if (kids[a].size()) {
			upd.insert(kids[a][0]);upd.insert(kids[a][1]);
		} if (kids[b].size()) {
			upd.insert(kids[b][0]);upd.insert(kids[b][1]);
		}
		for (int i : upd) bad -= wrong[i];
		
		swap(perm[a],perm[b]);
		wrong[a] = !check(a);
		if (kids[a].size()) {
			wrong[kids[a][0]] = !check(kids[a][0]);
			wrong[kids[a][1]] = !check(kids[a][1]);
		}
		wrong[b] = !check(b);
		if (kids[b].size()) {
			wrong[kids[b][0]] = !check(kids[b][0]);
			wrong[kids[b][1]] = !check(kids[b][1]);
		}

		for (int i : upd) bad += wrong[i];

		if (bad==0) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}