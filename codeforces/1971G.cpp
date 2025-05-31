#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
	int n,inp; cin>>n;
	vector<int> a(n);
	unordered_map<int, array<int, 4>, custom_hash> vals;
	for (int i=0;i<n;i++) {
		cin>>a[i];
		vals[a[i]>>2][a[i]&3]++;
	}
	vector<int> ans(n);
	for (int i=0;i<n;i++) {
		int bm = a[i]>>2;
		for (int j=0;j<4;j++) {
			if (vals[bm][j]) {
				vals[bm][j]--;
				ans[i] = (bm<<2) + j;
				break;
			}
		}
	}
	for (int x : ans)
		cout << x << " ";
	cout << endl;
}

int main() {
	int T;cin>>T;
	while (T --> 0) {
		solve();
	}
	return 0;
}