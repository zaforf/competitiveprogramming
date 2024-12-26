#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> end(n);
	for (int& i : end) cin>>i;
	vector<pair<int,int>> ans;
	vector<bool> done(n+1);
	for (int i=n-1;i>=0;i--) {
		int p = end[i];
		done[p] = 1;
		// backward pass
		for (int j=p-1;j>=1;j--)
			if (done[j]) continue;
			else ans.push_back({p,j});
		// forward pass
		for (int j=1;j<=n;j++)
			if (done[j]) continue;
			else ans.push_back({j,p});
	}
	cout << ans.size() << '\n';
	for (auto& p : ans)
		cout << p.first << " " << p.second << '\n';
	return 0;
}