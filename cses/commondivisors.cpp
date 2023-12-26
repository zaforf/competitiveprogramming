#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1e6;
vector<int> occ(MAXN+1);

int main() {
	int N;cin>>N;
	int gcd=0;
	for (int i=0;i<N;i++) {
		int a;cin>>a;
		gcd = max(gcd,a);
		occ[a]++;
	}

	for (;gcd>0;gcd--) {
		int cnt=0;
		for (int i=gcd;i<MAXN+1;i+=gcd) cnt+=occ[i];
		if (cnt>=2) {
			cout<<gcd;
			break;
		}
	}
	return 0;
}