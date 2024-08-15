#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7+1;
vector<int> prime(MAX,0);

void solve() {
	int n; cin>>n;
	int r = 0;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		if (x%2==0) continue;
		r ^= prime[x];
	}
	if (r==0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
}

int main() {
	int T;cin>>T;
	prime[1] = 1;
	int x = 1;
	for (int i=2;i<MAX;i++)
		if (prime[i]==0) {
			prime[i]=x++;
			for (int j=i+i;j<MAX;j+=i)
				prime[j] = prime[i];
		}
	while (T --> 0) {
		solve();
	}
	return 0;
}