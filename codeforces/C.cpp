#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<int> dp(n,1);
	vector<int> a(n);
	for (int &i : a) cin >>i;
	sort(a.begin(),a.end());
	for (int i=0;i<n;i++) {
		for (int j=0;j<i;j++) {
			if (a[i] % a[j] == 0)
				dp[i] = max(dp[i],dp[j]+1);
		}
	}
	cout << *max_element(dp.begin(),dp.end());
	return 0;
}