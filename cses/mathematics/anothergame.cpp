#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while (t --> 0) {
		int n,inp,x=0;cin>>n;
		for (int i=0;i<n;i++) {
			cin>>inp;
			x |= inp%2;
		}
		cout << (x?"first\n":"second\n");
	}
	return 0;
}