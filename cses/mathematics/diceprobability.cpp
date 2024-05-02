#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int n,a,b;cin>>n>>a>>b;
	vector<double> d(n*6+1),p(n*6+1);
	d[0]=1;double tot;
	for (int j=0;j<n;j++) {
		tot=0;
		for (int i=1;i<n*6+1;i++) {
			for (int j=i-1;j>=0 && j>=i-6;j--)
				p[i] += d[j];
			tot += p[i];
		}
		for (int i=0;i<n*6+1;i++)
			p[i]/=tot;
		for (int i=0;i<n*6+1;i++)
			p[i]-=(d[i]=p[i]);
	}
	cout << fixed << setprecision(6) << accumulate(d.begin()+a,d.begin()+b+1,0.0);
	return 0;
}