#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int N;cin>>N;
	vector<pair<int,int>> coords;
	for (int i=0;i<N;i++) {
		int a,b;cin>>a>>b;
		coords.push_back({a,b});
		// cout<<a<<" "<<b<<"\n";
	}

	sort(coords.begin(),coords.end());
	long long ans = 0;
	for (int i=0;i<N;i++) {
		ordered_set<int> ys; ys.insert(coords[i].second);
		for (int j=i+1;j<N;j++) {
			// cout<<"index "<<i<<" "<<j<<endl;
			int left=0,right=0;
			if (coords[i].second>coords[j].second) {
				left = j-i-ys.order_of_key(coords[i].second);
				right = ys.order_of_key(coords[j].second)+1;
				// cout<<left<<" "<<right<<endl;
				ans += left*right;
			} else {
				left = ys.order_of_key(coords[i].second)+1;
				right = j-i+1-ys.order_of_key(coords[j].second);
				// cout<<left<<" "<<right<<endl;
				ans += left*right;
			}
			ys.insert(coords[j].second);
		}
	}
	cout<<ans+N+1<<endl;
	return 0;
}