#include <bits/stdc++.h>
using namespace std;

vector<int> rate;
long long N,T;

bool work(long long time) {
	long long amt=0;
	for (int r : rate) {
		amt += time/r;
		if (amt>=T) return true;
	}
	return amt >= T;
}

long long binsearch(long long l, long long r) {
	r++;
	while (l<r) {
		long long m = (l+r)/2;
		if (work(m))
			r=m;
		else 
			l=m+1;
	}
	return l;
}

int main() {
	cin>>N>>T;
	rate.resize(N);
	for (auto& r : rate) cin>>r;
	cout << binsearch(1,(long long) 1e18);
	return 0;
}