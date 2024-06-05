#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<int,int>,int>
#define f first
#define s second

int main() {
	int n;cin>>n;
	vector<pii> ranges(n);
	bool contains[n] = {0},contained[n] = {0};
	for (pii& i : ranges) cin>>i.f.f>>i.f.s;
	for (int i=0;i<n;i++) ranges[i].s=i;
	sort(ranges.begin(),ranges.end(),[](pii a, pii b) {
		return (a.f.f==b.f.f ? a.f.s>b.f.s : a.f.f<b.f.f);
	});
	int mx=0;
	for (int i=0;i<n;i++) {
		if (mx>=ranges[i].f.s) contained[ranges[i].s] = true;
		else mx=ranges[i].f.s;
	}
	sort(ranges.begin(),ranges.end(),[](pii a, pii b) {
		return (a.f.s==b.f.s ? a.f.f>b.f.f : a.f.s<b.f.s);
	});
	mx = 0;
	for (int i=0;i<n;i++) {
		if (mx>=ranges[i].f.f) contains[ranges[i].s] = true;
		else mx=ranges[i].f.f;
	}
	for (bool x : contains)
		cout << (int) x << " ";
	cout << "\n";
	for (bool x : contained)
		cout << (int) x << " ";
	return 0;
}