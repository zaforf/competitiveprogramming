#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while (T--) {
		int n;cin>>n;
		vector<int> vals(n);
		for (int i=0;i<n;i++) {
			cin>>vals[i];vals[i]+=i;
		}
		multiset<pair<int,int>> ms; 
		int ans=0;
		for (int i=0;i<n;i++) {
			ms.insert(make_pair(-vals[i],i));
			if (ms.size()>2) {
				pair<int,int> p1=*ms.begin(),p2=*++ms.begin(),p3=*++++ms.begin();
				ans = max(-(p1.first+p2.first+p3.first)-p1.second-p2.second-p3.second-(max(p1.second,max(p2.second,p3.second))-min(p1.second,min(p2.second,p3.second))),ans);
			}	
		}
		for (pair<int,int> p : ms)
			cout<<p.first<<" "<<p.second<<"\n";
		cout<<ans;
		cout<<"\n";
	}
	return 0;
}