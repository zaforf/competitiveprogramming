#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int N;cin>>N;
	ordered_set<int> ord;
	vector<int> x(N);
	for (int i=0;i<N;i++) {
		cin>>x[i];
		ord.insert(i);
	}
	for (int i=0;i<N;i++) {
		int q;cin>>q;q--;
		auto it = ord.find_by_order(q);
		cout<<x[*it]<<" \n"[i==N-1];
		ord.erase(it);
	}
	return 0;
}