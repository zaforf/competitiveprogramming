#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while (t --> 0) {
		int n,inp,x=0;cin>>n;
		while (n --> 0) {
			cin>>inp;
			x ^= inp%4;
		}
		cout << (x?"first\n":"second\n");
	}
	return 0;
}