#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while (T --> 0) {
		int k, trash; cin>>k;
		int a[k];
		for (int i=0;i<k;i++) {
			cin >> a[i];
			for (int j=0;j<a[i]-1;j++) cin>>trash;
		}
		vector<int> set(20,0);
		for (int i=0;i<k;i++) {
			for (int j=0;j<20;j++)
				if (a[i]&(1<<j)) set[j]++;
		}
		int ans = 0;
		for (int i=19;i>=0;i--) {
			if (set[i]>1) {
				ans += (1<<(i+1))-1;
				break;
			} else if (set[i])
				ans += (1<<i);
		}
		cout << ans << '\n';
	}
	return 0;
}