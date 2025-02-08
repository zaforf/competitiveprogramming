#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	map<int,int> mp;
	for (int i=0;i<n;i++) {
		int inp; cin>>inp;
		mp[inp]++;
	}
	int res = 0;
	int odd = 0;
	bool insig = 0;
	for (pair<int,int> p : mp) {
		if (p.first % 2) {
			res ^=  p.second;
		}
	}
	if (res) {
		cout << "Ai";
	} else {
		cout << "Bo";
	}
	return 0;
}