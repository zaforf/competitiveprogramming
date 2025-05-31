#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; string s; cin>>n>>s;
	int since0 = -1, first1 = -1;
	vector<int> gaps;
	for (int i=0;i<n;i++) {
		if (s[i] == '0') {
			if (since0 > -1) gaps.push_back(i-since0);
			since0 = i;
		} else if (first1 < 0)
			first1 = i;
	}
	vector<int> dp(n);
	dp[first1]++;
	for (int i=first1;i<n;i++) {
		
	}
	return 0;
}