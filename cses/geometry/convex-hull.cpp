#include <bits/stdc++.h>
using namespace std;
#define int long long

struct point {
	int x,y;
	void read() {
		cin >> x >> y;
	}
	int cross(point a, point b) {
		return (b.x-a.x)*(y-a.y)-(b.y-a.y)*(x-a.x);
	}
};


int32_t main() {
	int n;cin>>n;
	vector<point> pts(n);
	vector<bool> hull(n);
	for (point& i : pts) i.read();
	sort(pts.begin(),pts.end(),[](point a, point b) {
		return (a.x==b.x ? a.y<b.y : a.x<b.x);
	});
	vector<int> stack;
	for (int i=0;i<n;i++) {
		while (stack.size()>1 && pts[i].cross(pts[stack.end()[-2]],pts[stack.end()[-1]])>0)
			stack.pop_back();
		stack.push_back(i);
	}
	for (int i : stack) hull[i] = true;
	stack.clear();
	for (int i=0;i<n;i++) {
		while (stack.size()>1 && pts[i].cross(pts[stack.end()[-2]],pts[stack.end()[-1]])<0)
			stack.pop_back();
		stack.push_back(i);
	}
	for (int i : stack) hull[i] = true;
	cout << accumulate(hull.begin(),hull.end(),0) << endl;
	for (int i=0;i<n;i++)
		if (hull[i])
			cout << pts[i].x << " " << pts[i].y << endl;
	return 0;
}