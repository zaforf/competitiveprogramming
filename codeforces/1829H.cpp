#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

void solve() {
	int N,K;cin>>N>>K;
	vector<int> ans(64);
	for (int i=0;i<N;i++) {
		int A;cin>>A;
		for (int j=0;j<64;j++) {
			ans[j&A]+=ans[j];
			ans[j&A]%=MOD;
		}
		ans[A]++;
	}
	int ret=0;
	for (int i=0;i<64;i++) {
		if (__builtin_popcount(i)==K) {
			ret+=ans[i]%MOD;
			ret%=MOD;
		}
	}
	cout<<ret<<"\n";
}

int main() {
	int T;cin>>T;
	while (T--)
		solve();
	return 0;
}