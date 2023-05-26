#include <bits/stdc++.h>
using namespace std;

int solve() {
	int a,b;cin>>a>>b;
	for (int i=2;i<=b&&i*i<=a;i++) {
		if (a%i==0) {
			cout<<"NO"<<"\n";
			return 0;
		}
	}
	cout<<(a<=b&&a!=1?"NO":"YES")<<"\n";
	return 0;
}

int main() {
	int T;cin>>T;
	while (T--) {
		solve();
	}
	return 0;
}