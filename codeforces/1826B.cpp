#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	while (T--) {
		int n;cin>>n;
		vector<int> vals(n);
		for (int i=0;i<n;i++)
			cin>>vals[i];
		int ans=0;
		for (int i=0;i<n/2;i++)
			ans = gcd(ans,abs(vals[i]-vals[n-i-1]));
		cout<<ans<<"\n";
	}
	return 0;
}