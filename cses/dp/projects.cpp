#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> ind;

int getIndex(int a) {
	return lower_bound(ind.begin(),ind.end(),a)-ind.begin();
}

int32_t main() {
	int n;cin>>n;
	vector<vector<int>> pjs(n,vector<int>(3));
	for (int i=0;i<n;i++) {
		int a,b,c;cin>>a>>b>>c;
		ind.push_back(a);ind.push_back(b);
		pjs[i][0]=a;
		pjs[i][1]=b;
		pjs[i][2]=c;
	}
	sort(ind.begin(),ind.end());
	sort(pjs.begin(),pjs.end(),[](auto &left, auto &right) {
    	return left[1] < right[1];
	});
	int dp[ind.size()+1] = {0};
	for (int i=0;i<pjs.size();i++) {
		pjs[i][0] = getIndex(pjs[i][0])+1;
		pjs[i][1] = getIndex(pjs[i][1])+1;
	}
	int ptr=0;
	for (int i=1;i<ind.size()+1;i++) {
		dp[i] = dp[i-1];
		while (ptr<pjs.size() && i==pjs[ptr][1]) {
			dp[i] = max(dp[i],dp[pjs[ptr][0]-1]+pjs[ptr][2]);
			ptr++;
		}
	}
	cout << dp[ind.size()] << endl;
	return 0;
}