#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;cin>>N;
	vector<long long> A(N);
	for (auto& a : A) cin>>a;
	long long ans=0;
	if (N<4)
		cout<<accumulate(A.begin(),A.end(),0,[](long long a, long long b) {return a|b;});
	else {
		for (int i=0;i<N;i++)
			for (int j=i+1;j<N;j++)
				for (int k=j+1;k<N;k++)
					ans=max(ans,A[i]|A[j]|A[k]);
		cout<<ans;
	}
	return 0;
}