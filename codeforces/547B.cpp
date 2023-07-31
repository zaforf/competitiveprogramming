#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;cin>>N;
	vector<int> A(N);
	for (int i=0;i<N;i++) cin>>A[i];
	stack<pair<int,int>> s;
	vector<int> R(N),L(N);
	for (int i=0;i<N;i++) {
		while (!s.empty() && s.top().first>=A[i])
			s.pop();
		R[i]=(!s.empty())?s.top().second:-1;
		s.push({A[i],i});
	}
	while (!s.empty()) s.pop();
	for (int i=N-1;i>=0;i--) {
		while (!s.empty() && s.top().first>=A[i])
			s.pop();
		L[i]=(!s.empty())?s.top().second:N;
		s.push({A[i],i});
	}
	vector<int> ans(N+1,0);
	for (int i=0;i<N;i++)
		ans[L[i]-R[i]-1]=max(ans[L[i]-R[i]-1],A[i]);
	for (int i=N-1;i>=0;i--)
		ans[i]=max(ans[i],ans[i+1]);
	for (int i=1;i<N+1;i++)
		cout<<ans[i]<<" ";
	return 0;
}
