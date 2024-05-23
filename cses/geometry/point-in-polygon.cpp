#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point {
	int x,y;
	void read() {
		cin >> x >> y;
	}
	int dot(point b) {
		return x*b.x + y*b.y;
	}
	int cross(point a, point b) {
		return (b.x-a.x)*(y-a.y)-(b.y-a.y)*(x-a.x);
	}
	bool on_seg(point a, point b) {
		if (cross(a,b)!=0)
			return false;
		return (min(a.x,b.x)<=x && max(a.x,b.x)>=x)
		&&	   (min(a.y,b.y)<=y && max(a.y,b.y)>=y);
	}
};

int sign(int x) {
	return (x>0)-(x<0);
}

double dist(int a, int b, int c, int d) {
	if (a==c && b==d) return 1;
	return sqrt((c-a)*(c-a) + (d-b)*(d-b));
}

bool intersect(point a, point b, point c, point d) {
		int z1 = (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
		int z2 = (b.x-a.x)*(d.y-a.y)-(b.y-a.y)*(d.x-a.x);
		double d1 = ((b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y))/dist(a.x,a.y,c.x,c.y);
		double d2 = ((b.x-a.x)*(d.x-a.x)+(b.y-a.y)*(d.y-a.y))/dist(a.x,a.y,d.x,d.y);
		double d3 = ((a.x-b.x)*(c.x-b.x)+(a.y-b.y)*(c.y-b.y))/dist(b.x,b.y,c.x,c.y);
		double d4 = ((a.x-b.x)*(d.x-b.x)+(a.y-b.y)*(d.y-b.y))/dist(b.x,b.y,d.x,d.y);
		return (a.on_seg(c,d) || b.on_seg(c,d) || d.on_seg(a,b) || c.on_seg(a,b)
			|| (abs(sign(z1)+sign(z2))!=2 && (d1+d2)>-1e-10 && (d3+d4)>-1e-10));
}

int32_t main() {
	int n,m;cin>>n>>m;
	vector<point> polygon(n);
	for (point& i : polygon) i.read();
	polygon.push_back(polygon[0]);
	for (int i=0;i<m;i++) {
		point p; p.read();
		point out = {p.x+1, 1'000'000'000ll};
		int count=0;bool bound=false;
		for (int j=0;j<n;j++) {
			point a = polygon[j];
			point b = polygon[j+1];
			bound |= p.on_seg(a,b);
			if (intersect(p,out,a,b)) count++;
		}
		cout << (bound ? "BOUNDARY\n" : (count%2 ? "INSIDE\n" : "OUTSIDE\n"));
	}
	return 0;
}