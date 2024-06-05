#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define int long long

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define pii pair<int,int>

int32_t main() {
	int n,k;cin>>n>>k;
	int v[n],cost=0;
	for (int& i : v) cin >> i;
	ordered_set<pii> ord;
	for (int i=0;i<k;i++) ord.insert({v[i],i});
	int med = (*ord.find_by_order((k-1)/2)).first,newmed;
	for (int i=0;i<k;i++) cost += abs(v[i]-med);
	for (int i=0;i<n-k+1;i++) {
		cout << cost << " ";
		ord.erase({v[i],i});
		ord.insert({v[i+k],i+k});
		newmed = (*ord.find_by_order((k-1)/2)).first;
		cost -= abs(v[i]-med);
		cost += abs(v[i+k]-med);

		int nummedians = ord.order_of_key({newmed+1,-1})-ord.order_of_key({newmed,-1});
		cost += (newmed-med)*(ord.order_of_key({newmed+1,-1})-(newmed>med?nummedians:0));
		cost += -(newmed-med)*(k-(ord.order_of_key({newmed+1,-1})-(newmed>med?nummedians:0)));

		med = newmed;
	}
	return 0;
}