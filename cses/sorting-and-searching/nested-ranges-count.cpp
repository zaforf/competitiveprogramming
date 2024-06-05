#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pii pair<pair<int,int>,int>
#define f first
#define s second

int main() {
	int n;cin>>n;
	vector<pii> ranges(n);
	int contains[n] = {0},contained[n] = {0};
	for (pii& i : ranges) cin>>i.f.f>>i.f.s;
	for (int i=0;i<n;i++) ranges[i].s=i;
	sort(ranges.begin(),ranges.end(),[](pii a, pii b) {
		return (a.f.f==b.f.f ? a.f.s>b.f.s : a.f.f<b.f.f);
	});
	ordered_multiset<int> ord;
	for (int i=0;i<n;i++) {
		contained[ranges[i].s] = ord.size()-ord.order_of_key(ranges[i].f.s);
		ord.insert(ranges[i].f.s);
	}
	sort(ranges.begin(),ranges.end(),[](pii a, pii b) {
		return (a.f.s==b.f.s ? a.f.f>b.f.f : a.f.s<b.f.s);
	});
	ord.clear();
	for (int i=0;i<n;i++) {
		contains[ranges[i].s] = ord.size()-ord.order_of_key(ranges[i].f.f);
		ord.insert(ranges[i].f.f);
	}
	for (int x : contains)
		cout << x << " ";
	cout << "\n";
	for (int x : contained)
		cout << x << " ";
	return 0;
}