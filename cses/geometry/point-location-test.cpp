#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		int x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		//   i  ,  j  ,	k
		// x2-x1,y2-y1,	0
		// x3-x1,y3-y1,	0
		int z = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
		if (z>0)
			cout << "LEFT";
		else if (z<0)
			cout << "RIGHT";
		else
			cout << "TOUCH";
		cout << "\n";
	}
	return 0;
}