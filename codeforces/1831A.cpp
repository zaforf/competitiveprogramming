#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	for (int i=0;i<T;i++) {
		int N;cin>>N;
		for (int j=0;j<N;j++) {
			int a;cin>>a;
			cout<<N-a+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}