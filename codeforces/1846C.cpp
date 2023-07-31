#include <bits/stdc++.h>
using namespace std;
# define int long long

int32_t main() {
	int T;cin>>T;
	while (T--) {
		vector<pair<int,int>> parts;
		int N,M,H;cin>>N>>M>>H;
		int x,y;
		for (int i=0;i<N;i++) {
			vector<int> t(M);
			for (auto& a : t) cin>>a;
			sort(t.begin(),t.end());
			int j,b=0; for (j=0;j<M&&b+t[j]<=H;j++) b+=t[j];
			int c=0,ct=0;
			for (int k=0;k<j;k++) {ct+=t[k];c+=ct;}
			parts.push_back({-j,c});
			if (i==0) x=-j,y=c;
		}
		sort(parts.begin(),parts.end());
		for (int i=0;i<N;i++)
			if (parts[i].first==x && parts[i].second==y) {
				cout<<i+1<<"\n";break;
			}
	}
	return 0;
}