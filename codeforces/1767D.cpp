#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	string s; cin>>s;
	int l = 0, r = 0;
	for (int i=0;i<n;i++) {
		if (s[i]=='0') r = (r<<1) | 1;
		else l = (l<<1) | 1;
	}
	for (int i=l+1;i<=(1<<n)-r;i++)
		cout << i << " ";
	return 0;
}