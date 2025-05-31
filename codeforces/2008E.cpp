#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; string s; cin>>n>>s;
	vector<vector<int>> even(n, vector<int>(26)), odd(n, vector<int>(26));
	vector<int> tot_even(26), tot_odd(26);
	int l_even=0, l_odd=0;
	for (int i=0;i<n;i++) {
		if (i&1) {
			odd[i][s[i]-'a']++; tot_odd[s[i]-'a']++; l_odd++;
		}
		else {
			even[i][s[i]-'a']++; tot_even[s[i]-'a']++; l_even++;
		}
	}
	for (int i=1;i<n;i++) {
		for (int j=0;j<26;j++) {
			even[i][j] += even[i-1][j];
			odd[i][j] += odd[i-1][j];
		}
	}
	bool is_odd = n & 1;
	int ans = 1e9;
	if (is_odd) {
		for (int k=0;k<n;k++) {
			for (int i=0;i<26;i++) {
				for (int j=0;j<26;j++) {
					int match_even = (k ? even[k-1][i] : 0) + (tot_odd[i] - odd[k][i]);
					int match_odd = (k ? odd[k-1][j] : 0) + (tot_even[j] - even[k][j]);
					int ce = l_even - match_even;
					int co = l_odd - match_odd;
					ans = min(ans, ce+co);
				}
			}
		}
	} else {
		for (int i=0;i<26;i++) {
			for (int j=0;j<26;j++) {
				int ce = l_even - tot_even[i];
				int co = l_odd - tot_odd[j];
				ans = min(ans, ce+co);
			}
		}
	}
	cout << ans << endl;
	
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}