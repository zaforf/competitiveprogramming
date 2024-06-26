#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while (T --> 0) {
		int a1,a2,b1,b2;cin>>a1>>b1>>a2>>b2;
		cout << (((a1<b1)^(a2<b2))?"NO":"YES") << endl;
	}
	return 0;
}