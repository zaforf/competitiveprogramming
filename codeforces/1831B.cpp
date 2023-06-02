#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4*1e5+1;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;cin>>T;
	for (int i=0;i<T;i++) {
		int N;cin>>N;
		vector<int> count1(2*N+1,0),count2(2*N+1,0);
		vector<int> c1(N);
		for (int& i : c1) cin>>i;
		int cnt=1;
		for (int j=1;j<N;j++) {
			if (c1[j]==c1[j-1])
				cnt++;
			else {
				count1[c1[j-1]]=max(count1[c1[j-1]],cnt);cnt=1;
			}
		}
		count1[c1[N-1]]=max(count1[c1[N-1]],cnt);
		vector<int> c2(N);
		for (int& i : c2) cin>>i;
		cnt=1;
		for (int j=1;j<N;j++) {
			if (c2[j]==c2[j-1])
				cnt++;
			else {
				count2[c2[j-1]]=max(count2[c2[j-1]],cnt);cnt=1;
			}
		}
		count2[c2[N-1]]=max(count2[c2[N-1]],cnt);

		int ans=0;
		for (int j=1;j<=2*N;j++)
			ans = max(ans,count1[j]+count2[j]);
		cout<<ans<<"\n";
	}
	return 0;
}