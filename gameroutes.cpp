#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<vector<int>> inadj,outadj;
vector<int> order;
vector<long long> ans;
bool vis[MAXN];
const int MOD=1000000007;

void dfs(int node) {
	vis[node]=true;
	for (int nb : outadj[node])
		if (!vis[nb])
			dfs(nb);
	order.push_back(node);
}

int main() {
	int N,M;cin>>N>>M;
	inadj.resize(N+1);outadj.resize(N+1);
	for (int i=0;i<M;i++) {
		int a,b;cin>>a>>b;
		outadj[a].push_back(b);
		inadj[b].push_back(a);
	}
	for (int i=1;i<N+1;i++) if (!vis[i]) dfs(i);
	reverse(begin(order),end(order));
	ans.resize(N+1);
	ans[1]=1;
	for (int n : order) {
		for (int nb : inadj[n]) {
			ans[n]+=ans[nb]%MOD;
			ans[n]%=MOD;
		}
	}
	cout<<ans[N];
	return 0;
}