#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1000000000000;

void solve() {
	long long n,k; cin>>n>>k;
	string s; cin>>s;
	vector<int> a(n);
	for (int& x : a) cin>>x;
	vector<int> left(n), right(n);
	long long sum = 0, mx = 0;
	// kadanes algorithm for left max subarray sum
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		mx = max(mx, sum);
		if (s[i] == '0') {
			left[i] = sum;
			cnt++;
		}
		if (sum < 0 || s[i] == '0') sum = 0;
	}
	// same backwards, right
	sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += a[i];
		if (s[i] == '0') right[i] = sum;
		if (sum < 0 || s[i] == '0') sum = 0;
	}
	if (mx > k) {
		cout << "NO\n";
		return;
	} else if (mx == k) {
		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			if (s[i] == '0')
				cout << -MAX << " ";
			else
				cout << a[i] << " ";
		}
		cout << "\n";
	} else {
		if (cnt == 0) {
			cout << "NO\n";
			return;
		}
		cout << "YES\n";
		bool found = false;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (!found) {
					cout << (k-right[i]) - left[i] << " ";
					found = true;
				} else cout << -MAX << " ";
			} else {
				cout << a[i] << " ";
			}
		}
		cout << "\n";

	}

}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}