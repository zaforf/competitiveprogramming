#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	while (T --> 0) {
		int n,x;cin>>n>>x;
		long long ans=0;
		for (int a=1;a<=min(n,x);a++)
			for (int b=1;a*b<=n && a+b<=x;b++)
				ans += min((n-a*b)/(a+b),x-a-b);
		cout << ans << '\n';
	}
	return 0;
}