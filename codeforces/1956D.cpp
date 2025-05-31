#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> ans;

void magic(int start, int len) {
	if (len==0) return;
	if (len==1) {
		ans.push_back({start+1,start+1});
		return;
	}
	magic(start, len-1);
	ans.push_back({start+1,start+len});
	magic(start, len-1);
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for (int& i : a) cin>>i;
	int last = -1;
	int tot = 0, curr = 0;
	int best = 0;
	for (int mask=0;mask<(1<<n);mask++) {
		last = -1, curr = 0;
		for (int i=0;i<n;i++) {
			if (mask&(1<<i)) {
				curr += (i-last-1)*(i-last-1) + a[i];
				last = i;
			}
		}
		curr += (n-last-1)*(n-last-1);
		if (curr > tot) {
			tot = curr;
			best = mask;
		}
	}

	// bitset<18> b(best);
	// cout << tot << " " << b << endl;
	last = -1;
	for (int i=0;i<n;i++) {
		if (best&(1<<i)) {
			if (i==last+1) {
				last = i;
				continue;
			}
			magic(last+1, i-last-1);
			ans.push_back({last+2, i});
			last = i;
		} else if ((i==last+1 && a[i]==0) || (i>last+1 && a[i])) {
			ans.push_back({i+1,i+1});
		}
	}
	if (last<n-1) {
		magic(last+1, n-last-1);
		ans.push_back({last+2, n});
	}
	cout << tot << " " << ans.size() << endl;
	for (auto& p : ans) {
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}