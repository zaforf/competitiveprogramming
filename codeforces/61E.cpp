#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;cin>>N;
	set<int> box;
	vector<int> smaller(N);
	vector<int> A(N); for (auto& a : A) cin>>a;
	for (int i=N-1;i>=0;i--) {
		box.insert(A[i]);
		auto it = box.lower_bound(A[i]);
		smaller[i]=it - box.begin();
	}
	for (auto a : smaller)
		cout<<a<<" ";
	return 0;
}