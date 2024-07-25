#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while (T-->0) {
		int n,m,k;cin>>n>>m>>k;
		string riv; cin >> riv;
		vector<int> poss(n+2,1e9);
		poss[0] = 0;
		for (int i=1;i<n+2;i++) {
			if (riv[i-1]=='C') continue;
			for (int j=i-1;j>=max(i-m,0);j--) {
				if (j!=0 && riv[j-1]!='L') continue;
				poss[i] = min(poss[i],poss[j]);
			}
			if (riv[i-1]=='W') poss[i] = min(poss[i],poss[i-1]+1);
			if (i>1 && (i==n+1 || riv[i-1]=='L') && riv[i-2]=='W') poss[i] = min(poss[i],poss[i-1]+1);
		}
		cout << ((poss[n+1]<=k)?"YES":"NO") << endl;
	}
	return 0;
}