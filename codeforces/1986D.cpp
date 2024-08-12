#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin>>n;
	if (n==2) {
		int a; cin>>a;
		cout << a << '\n';
		return;
	}
	string s; cin>>s;
	vector<int> left(n+2,1), right(n+2,1);
	left[1] = s[0]-'0';
	right[n] = s[n-1]-'0';
	for (int i=1;i<n;i++) {
		int c = s[i]-'0';
		left[i+1] = min(left[i]*c,left[i]+c);
	}
	for (int i=n-2;i>=0;i--) {
		int c = s[i]-'0';
		right[i+1] = min(right[i+2]*c,right[i+2]+c);
	}
	int ans = INT_MAX;
	for (int i=0;i<n-1;i++) {
		int c = (s[i]-'0')*10 + s[i+1]-'0';
		ans = min(ans,min(min(left[i]+c+right[i+3],left[i]*c+right[i+3]),min(left[i]+c*right[i+3],left[i]*c*right[i+3])));
	}
	cout << ans << '\n';
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}