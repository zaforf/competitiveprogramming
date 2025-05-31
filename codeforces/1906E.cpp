#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> ind(2*n+1);
	vector<int> a(2*n);
	int min_i = 2*n;
	for (int i=0;i<2*n;i++) {
		int inp; cin>>inp;
		a[i] = inp;
		ind[inp] = i;
	}	

	vector<vector<int>> strs(2*n+1);
	for (int i=2*n;i>0;i--) {
		if (min_i < ind[i]) continue;
		for (int j=ind[i];j<min_i;j++) {
			strs[i].push_back(a[j]);
		}
		min_i = ind[i];
	}

	vector<unordered_set<int>> dp(n+1);
	for (int i=1;i<2*n+1;i++) {
		int len = strs[i].size();
		if (!len) continue;
		for (int j=n;j>len;j--) {
			if (!dp[j].empty()) continue;
			if (!dp[j-len].empty()) {
				dp[j] = dp[j-len];
				dp[j].insert(i);
			}
		}
		if (len < n + 1) {
			if (!dp[len].empty()) continue;
			dp[len] = dp[0];
			dp[len].insert(i);
		}
	}
	if (dp[n].empty()) {
		cout << "-1\n";
	} else {
		for (int i=1;i<2*n+1;i++)
			if (strs[i].size() && dp[n].contains(i))
				for (int v : strs[i])
					cout << v << " ";
		cout << endl;
		for (int i=1;i<2*n+1;i++)
			if (strs[i].size() && !dp[n].contains(i)) {
				for (int v : strs[i])
					cout << v << " ";
			}
	}
	return 0;
}