#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	while (T--) {
		int N;cin>>N;
		vector<int> A(N);
		for (int i=0;i<N;i++) cin>>A[i];
		int min = A[0];
		for (int i=1;i<N;i++) min &= A[i];
		vector<int> AND(N); AND[N-1]=A[N-1];
		for (int i=N-2;i>=0;i--)
			AND[i] = AND[i+1]&A[i];
		int curr = -1,ans=1;
		if (min==0) {
			for (int i=0;i<N-1;i++) {
				curr = (curr==-1?A[i]:curr&A[i]);
				if (curr==min && AND[i+1]==min) {
					ans++;
					curr = -1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}