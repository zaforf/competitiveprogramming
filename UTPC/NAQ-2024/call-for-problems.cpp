#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<int> a(n);
	int ans = 0;
	for (int& i : a) {
		cin>>i;
		ans += (i%2);
	}
	cout << ans << endl;
	return 0;
}