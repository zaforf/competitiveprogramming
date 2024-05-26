#include <bits/stdc++.h>
using namespace std;
#define int long long

int sign(int x) {
	return (x>0)-(x<0);
}
double dist(int a, int b, int c, int d) {
	if (a==c && b==d) return 1;
	return sqrt((c-a)*(c-a) + (d-b)*(d-b));
}


int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		int x1,y1,x2,y2,x3,y3,x4,y4;
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		// cross products:
		// to check that the points are on
		// opposite sides of the segment
		int z1 = (x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
		int z2 = (x2-x1)*(y4-y1)-(y2-y1)*(x4-x1);
		// dot products:
		// to check that the points are in the
		// right region to intersect
		double d1 = ((x2-x1)*(x3-x1)+(y2-y1)*(y3-y1))/dist(x1,y1,x3,y3);
		double d2 = ((x2-x1)*(x4-x1)+(y2-y1)*(y4-y1))/dist(x1,y1,x4,y4);
		double d3 = ((x1-x2)*(x3-x2)+(y1-y2)*(y3-y2))/dist(x2,y2,x3,y3);
		double d4 = ((x1-x2)*(x4-x2)+(y1-y2)*(y4-y2))/dist(x2,y2,x4,y4);
		if ((!z1 && d1>=0 && d3>=0) || (!z2 && d2>=0 && d4>=0) || (abs(sign(z1)+sign(z2))!=2 && (d1+d2)>-1e-10 && (d3+d4)>-1e-10))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}