#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
vector<vector<int>> inadj,outadj;
vector<int> order;
vector<pair<int,int>> ans;
bool vis[MAXN];

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
	ans.resize(N+1,{0,-1});
	ans[1].first=1;
	for (int n : order) {
		for (int nb : inadj[n]) {
			if (ans[nb].first!=0 && ans[nb].first+1>ans[n].first) {
				ans[n].first=ans[nb].first+1;
				ans[n].second=nb;
			}
		}
	}
	if (ans[N].second==-1) cout<<"IMPOSSIBLE";
	else {
		cout<<ans[N].first<<"\n";
		vector<int> temp;temp.push_back(N);
		while (ans[temp.back()].second!=-1)
			temp.push_back(ans[temp.back()].second);
		reverse(begin(temp),end(temp));
		for (auto a : temp)
			cout<<a<<" ";
	}
	return 0;
}