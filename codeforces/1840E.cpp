#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	while (T--) {
		string s[2];
		cin>>s[0]>>s[1];
		int t,Q;cin>>t>>Q;
		queue<int> blockd;	
		int bad=0;
		for (int i=0;i<s[0].size();i++)
			if (s[0][i]!=s[1][i])
				bad++;
		for (int i=0;i<Q;i++) {
			int r,f1,f2,p1,p2;cin>>r;
			if (r==1) {
				cin>>p1;p1--;
				if (s[0][p1]!=s[1][p1]) {
					bad--;
					blockd.push(i);
				}
			}
			else if (r==2) {
				cin>>f1>>p1>>f2>>p2;
				p1--;p2--;f1--;f2--;
				if (s[0][p1]!=s[1][p1])
					bad--;
				if (s[0][p2]!=s[1][p2])
					bad--;
				swap(s[f1][p1],s[f2][p2]);
				if (s[0][p1]!=s[1][p1])
					bad++;
				if (s[0][p2]!=s[1][p2])
					bad++;
			}
			else {
				while (!blockd.empty() && blockd.front()<=i-t) {
					blockd.pop();bad++;
				}
				if (!bad)
					cout<<"YES"<<"\n";
				else
					cout<<"NO"<<"\n";
			}
		}
	}
	return 0;
}