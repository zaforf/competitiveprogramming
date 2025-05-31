#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q; cin >> n >> q;
	string s; cin >> s;
	map<pair<int,int>,vector<int>> fwd_times, rev_times;
	vector<pair<int,int>> fwd_pos(1), rev_pos(n+1);
	fwd_times[{0,0}].push_back(0);
	pair<int,int> c = {0,0};
	for (int i=0;i<n;i++) {
		if (s[i] == 'U') {
			c.second++;
		} else if (s[i] == 'R') {
			c.first++;
		} else if (s[i] == 'D') {
			c.second--;
		} else if (s[i] == 'L') {
			c.first--;
		}
		fwd_pos.push_back(c);
		fwd_times[c].push_back(i+1);
	}
	c = {0,0};
	for (int i=0;i<n;i++) {
		if (s[n-i-1] == 'U') {
			c.second++;
		} else if (s[n-i-1] == 'R') {
			c.first++;
		} else if (s[n-i-1] == 'D') {
			c.second--;
		} else if (s[n-i-1] == 'L') {
			c.first--;
		}
		rev_pos[n-i-1] = c;
		rev_times[c].push_back(n-i);
	}

	for (int i=0;i<q;i++) {
		bool found = false;
		pair<int,int> c; cin >> c.first >> c.second;
		int l, r; cin >> l >> r;
		// seg 1: before reverse
		if (fwd_times[c].size() && fwd_times[c].front() < l) {
			found = true;
		}
		// seg 2: in reverse
		c.first -= fwd_pos[l-1].first;
		c.second -= fwd_pos[l-1].second;
		
		c.first += rev_pos[r].first;
		c.second += rev_pos[r].second;
		if (rev_times[c].size()) {
			auto it = lower_bound(rev_times[c].rbegin(), rev_times[c].rend(), l);
			if (it != rev_times[c].rend() && *it <= r)
				found = true;
		}
		c.first -= rev_pos[r].first;
		c.second -= rev_pos[r].second;

		c.first += fwd_pos[l-1].first;
		c.second += fwd_pos[l-1].second;

		// seg 3: after reverse
		if (fwd_times[c].size() && fwd_times[c].back() > r) {
			found = true;
		}
		cout << (found ? "YES\n" : "NO\n");
	}
	return 0;
}