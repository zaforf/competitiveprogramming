#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;cin>>n>>m;
	int ind[n+2]={(int)2e5+1};
	ind[n+1]=(int)2e5+1;
	int x[n];
	for (int i=0;i<n;i++) {
		cin>>x[i];
		ind[x[i]]=i;
	}
	int r=0;
	for (int i=1;i<=n;i++)
		if (ind[i]<ind[i-1]) r++;
	for (int j=0;j<m;j++) {
		int a,b;cin>>a>>b;a--;b--;

		if (x[a]>x[b]) swap(a,b);
		if (ind[x[a]]<ind[x[a]-1]) r--;
		if (abs(x[a]-x[b])>1 && ind[x[a]+1]<ind[x[a]]) r--;
		if (ind[x[b]]<ind[x[b]-1]) r--;
		if (ind[x[b]+1]<ind[x[b]]) r--;

		swap(x[a],x[b]);
		swap(ind[x[a]],ind[x[b]]);

		if (x[a]>x[b]) swap(a,b);
		if (ind[x[a]]<ind[x[a]-1]) r++;
		if (abs(x[a]-x[b])>1 && ind[x[a]+1]<ind[x[a]]) r++;
		if (ind[x[b]]<ind[x[b]-1]) r++;
		if (ind[x[b]+1]<ind[x[b]]) r++;

		cout<<r<<endl;
	}
	return 0;
}