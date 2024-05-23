#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second

int boundary_points(int x, int y, int a, int b) {
	int w = a-x;
	int h = b-y;
	return abs(gcd(w,h));
}

int32_t main() {
	int n;cin>>n;
	vector<pair<int,int>> a(n+1);
	for (int i=0;i<n;i++)
		cin>>a[i].f>>a[i].s;
	a[n].f=a[0].f;
	a[n].s=a[0].s;
	int area=0,bounds=0;
	// shoelace theorem
	for (int i=0;i<n;i++) {
		bounds += boundary_points(a[i].f,a[i].s,a[i+1].f,a[i+1].s);
		area += a[i].f*a[i+1].s - a[i].s*a[i+1].f;
	}
	cout << (abs(area)-bounds+2)/2 << " " << bounds;
	return 0;
}