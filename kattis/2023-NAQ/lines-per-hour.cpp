#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l; cin >> n >> l;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	sort(a.begin(),a.end());
	int tot = 0, ans = 0;
	l *= 5;
	for (int i : a) {
		if (tot + i <= l) {
			tot += i;
			ans++;
		} else break;
	}
	cout << ans;
	return 0;
}