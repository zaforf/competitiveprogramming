#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N;cin>>N;
	vector<int> A(N);
	for (int i=0;i<N;i++) cin>>A[i];
	if (A.back()) {
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	vector<int> ans;
	for (int i=1;i<N;i++)
		if (A[i]!=A[i-1])
			ans.push_back(i);
	for (int i=0;i<N-ans.size();i++)
		cout<<0<<" ";
	for (auto a : ans)
		cout<<a<<" ";
	cout<<"\n";
}

int main() {
	int T;cin>>T;
	while (T--) {
		solve();
	}
	return 0;
}