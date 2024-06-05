#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// multiset using less_equal<T> does not erase correctly
#define pii pair<int,int>

int main() {
	int n,k;cin>>n>>k;
	int v[n];
	for (int& i : v) cin >> i;
	ordered_set<pii> ord;
	for (int i=0;i<k;i++) ord.insert({v[i],i});
	for (int i=0;i<n-k+1;i++) {
		cout << (*ord.find_by_order((k-1)/2)).first << " ";
		ord.erase({v[i],i});
		ord.insert({v[i+k],i+k});
	}
	return 0;
}