#include <bits/stdc++.h>
using namespace std;

int mod (int a, int b) { return (a%b+b)%b; }

int main() {
	int N;cin>>N;
	vector<int> A(N);
	for (auto& a : A) cin>>a;
	vector<int> pmod (N,0);
	pmod[0]=1;
	long long prefix=0,ans=0;
	for (int i=0;i<N;i++) {
		prefix+=A[i];
		ans+=pmod[mod(prefix,N)];
		pmod[mod(prefix,N)]++;
		prefix = mod(prefix,N);
	}
	cout<<ans<<"\n";
	return 0;
}