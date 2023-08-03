#include <bits/stdc++.h>
using namespace std;

int N,M,C;
vector<int> arrivalTimes;

bool checkPossible(int x) {
	int cntBus=1,cntIn=0,ceil=arrivalTimes[0]+x;
	for (int i=0;i<N;i++) {
		if (cntIn==C || arrivalTimes[i]>ceil) {
			ceil = arrivalTimes[i]+x;
			cntBus++;cntIn=0;
		}	
		cntIn++;
	}
	return cntBus<=M;
}

int firstTrue(int l,int r) {
	while (l<r) {
		int m = (l+r)/2;
		if (checkPossible(m))
			r=m;
		else
			l=m+1;
	}
	return l;
}

int main() {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	cin>>N>>M>>C; arrivalTimes.resize(N);
	for (int i=0;i<N;i++) cin>> arrivalTimes[i];
	sort(arrivalTimes.begin(),arrivalTimes.end());
	cout<<firstTrue(0,int(1e9));
	return 0;
}