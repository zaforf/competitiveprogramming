#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while (T --> 0) {
		int n; cin>>n;
		string s,t; cin>>s>>t;sb
		int i=0,j=0;
		for (;i<n;i++)
			if (s[i]=='1') break;
		for (;j<n;j++)
			if (t[j]=='1') break;
		cout << (i>j ? "NO\n" : "YES\n");
	}
	return 0;
}