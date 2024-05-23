#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second

int32_t main() {
	int n;cin>>n;
	vector<pair<int,int>> a(n+1);
	for (int i=0;i<n;i++)
		cin>>a[i].f>>a[i].s;
	a[n].f=a[0].f;
	a[n].s=a[0].s;
	int area=0;
	// shoelace theorem
	for (int i=0;i<n;i++)
		area += a[i].f*a[i+1].s - a[i].s*a[i+1].f;
	cout << abs(area);
	return 0;
}