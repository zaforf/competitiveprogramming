#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	vector<vector<int>> rates(n, vector<int>(3));
	for (int i=0;i<3;i++)
		for (int j=0;j<n;j++)
			cin >> rates[j][i];
	vector<array<int,2>> trade(n+1); // k/q/j, num trading, traded for
	int bestq = rates[0][0], lastq = 1;
	int bestk = rates[0][1], lastk = 1;
	int bestj = rates[0][2], lastj = 1;
	for (int i=1;i<n;i++) {
		if (rates[i][0] < bestq) {
			trade[i + 1] = {0, lastq};
		}
		if (rates[i][1] < bestk) {
			trade[i + 1] = {1, lastk};
		}
		if (rates[i][2] < bestj) {
			trade[i + 1] = {2, lastj};
		}

		if ((rates[i][0] < bestq || rates[i][2] < bestj) && rates[i][1] > bestk) {
			bestk = rates[i][1];
			lastk = i + 1;
		}
		if ((rates[i][0] < bestq || rates[i][1] < bestk) && rates[i][2] > bestj) {
			bestj = rates[i][2];
			lastj = i + 1;
		}
		if ((rates[i][2] < bestj || rates[i][1] < bestk) && rates[i][0] > bestq) {
			bestq = rates[i][0];
			lastq = i + 1;
		}

	}
	if (trade[n][1]) {
		cout << "YES" << endl;
		vector<array<int,2>> ans;
		int p = n;
		while (p != 1) {
			ans.push_back({trade[p][0], p});
			p = trade[p][1];
		}
		cout << ans.size() << endl;
		while (ans.size()) {
			cout << "qkj"[ans.back()[0]] << " " << ans.back()[1] << endl;	
			ans.pop_back();
		}
	} else
		cout << "NO" << endl;

}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}