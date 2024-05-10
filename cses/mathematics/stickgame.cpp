#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k; cin>>n>>k;
	vector<int> p(k); bool dp[n+1] = {0};
	for (int& i : p) cin>>i;
	for (int i=1;i<=n;i++)
		for (int m : p) {
			if (i-m<0) continue;
			dp[i] |= !dp[i-m];
		}
	for (int i=1;i<=n;i++) cout << (dp[i]?"W":"L");
	return 0;
}