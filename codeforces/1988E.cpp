#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 5e5+1;

void solve() {
	int n; cin>>n;
	int a[n]; for (int& i : a) cin>>i;

	stack<int> s; vector<bool> cnt(n);
	vector<vector<int>> right(n,vector<int>(2,n));
	for (int i=0;i<n;i++) {
		stack<int> readd;
		while (s.size() && a[s.top()]>a[i]) {
			if (!cnt[s.top()]) readd.push(s.top());
			right[s.top()][cnt[s.top()]] = i;
			cnt[s.top()] = 1;
			s.pop();
		}
		s.push(i);
		while (readd.size()) s.push(readd.top()), readd.pop();
	}

	while (s.size()) s.pop();
	fill(cnt.begin(),cnt.end(),0);
	vector<vector<int>> left(n,vector<int>(2,-1));
	for (int i=n-1;i>=0;i--) {
		stack<int> readd;
		while (s.size() && a[s.top()]>a[i]) {
			if (!cnt[s.top()]) readd.push(s.top());
			left[s.top()][cnt[s.top()]] = i;
			cnt[s.top()] = 1;
			s.pop();
		}
		s.push(i);
		while (readd.size()) s.push(readd.top()), readd.pop();
	}

	vector<int> diff(n+2), pre(n+2);
	int tot = 0;
	for (int i=0;i<n;i++) {
		tot += (i-left[i][0])*(right[i][0]-i)*a[i];

		pre[left[i][0]+1+1] += (right[i][0]-i)*a[i];
		pre[i+1] -= (right[i][0]-i)*a[i];

		pre[i+1+1] += (i-left[i][0])*a[i];
		pre[right[i][0]+1] -= (i-left[i][0])*a[i];

		diff[left[i][0]+1] -= (i-left[i][0])*(right[i][0]-i)*a[i];
		diff[left[i][0]+1] += (i-left[i][1]-1)*(right[i][0]-i)*a[i];

		diff[right[i][0]+1] -= (i-left[i][0])*(right[i][0]-i)*a[i];
		diff[right[i][0]+1] += (i-left[i][0])*(right[i][1]-i-1)*a[i];
	}
	partial_sum(pre.begin(),pre.end(),pre.begin());
	for (int i=0;i<n;i++)
		cout << tot - pre[i+1] + diff[i+1] - (i-left[i][0])*(right[i][0]-i)*a[i] << " ";
	cout << '\n';
}

int32_t main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}