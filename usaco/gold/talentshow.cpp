#include <bits/stdc++.h>
using namespace std;

int talent[250*1000+1];

int main() {
	// freopen("talent.in", "r", stdin);
	// freopen("talent.out", "w", stdout);
	int N,W;cin>>N>>W;
	vector<pair<int,int>> vals(N,{0,0});
	fill_n(talent,end(talent)-begin(talent),1<<30);
	for (int i=0;i<N;i++) cin>>vals[i].first>>vals[i].second;
	for (int i=0;i<N;i++) {
		for (int j=250*1000+1;j>vals[i].second;j--)
			if (talent[j-vals[i].second]!=1<<30)
				talent[j]=min(talent[j-vals[i].second]+vals[i].first,talent[j]);
		talent[vals[i].second]=min(vals[i].first,talent[vals[i].second]);

	}
	int ans=0;
	for (int j=0;j<250*1000+1;j++) {
		if (talent[j]>=W)
			ans=max(ans,1000*j/talent[j]);
	}
	cout<<ans;
	return 0;
}