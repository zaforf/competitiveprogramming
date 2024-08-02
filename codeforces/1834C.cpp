#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while (T --> 0) {
		int n; cin>>n;
		string s1,s2; cin>>s1>>s2;
		int cntf = 0, cntr = 0;
		for (int i=0;i<n;i++) {
			if (s1[i]!=s2[i]) cntf++;
			if (s1[i]!=s2[n-i-1]) cntr++;
		}
		if (cntf==0) cout << "0\n";
		else if (cntr==0) cout << "2\n";
		else cout << min(cntr*2-(cntr%2?0:1),cntf*2-(cntf%2)) << '\n';
	}
	return 0;
}