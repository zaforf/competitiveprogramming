#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	while (T --> 0) {
		int n;cin>>n;
		vector<int> a(n),b(n);
		for (int& i : a) cin >> i;
		for (int& i : b) cin >> i;
		int x=0,y=0,ans=0;
		while (y<n) {
			if (a[x]>b[y]) ans++;
			else x++;
			y++;
		}
		cout << ans << endl;
	}
	return 0;
}