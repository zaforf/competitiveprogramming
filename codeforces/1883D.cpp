#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	multiset<int> left, right;
	for (int i=0;i<n;i++) {
		char o; int a, b; cin>>o>>a>>b;
		if (o == '+') {
			left.insert(a);
			right.insert(b);
		} else {
			left.erase(left.find(a));
			right.erase(right.find(b));
		}

		// cout << (*right.begin()) << " " << (*left.rbegin()) << endl;
		if (!left.empty() && (*right.begin() < *left.rbegin()))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}