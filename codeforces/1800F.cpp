#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<string> s(n);
	for (int i=0;i<n;i++)
		cin>>s[i];
	vector<int> odds(n), exists(n);
	long long ans = 0;
	for (int i=0;i<n;i++) {
		int l = s[i].size();
		for (int j=0;j<l;j++) {
			odds[i] ^= 1 << (s[i][j]-'a');
			exists[i] |= 1 << (s[i][j]-'a');
		}
	}
	for (int j=0;j<26;j++) {
		unordered_map<int,int> cnt;
		for (int i=0;i<n;i++)
			if (!(exists[i] & (1<<j))) {
				ans += cnt[odds[i] ^ ((1 << 26) - 1 - (1<<j))];
				cnt[odds[i]]++;
			}
	}
	cout << ans;
	return 0;
}