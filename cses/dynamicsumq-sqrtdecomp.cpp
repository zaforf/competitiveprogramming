#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> a;
vector<int> squirt(448);

void upd(int i, int inp) {
	squirt[i/447] += inp-a[i];
	a[i] = inp;
}

int qry(int r) {
	int ret = 0;
	for (int i=0;i<r/447;i++)
		ret += squirt[i];
	for (int i=(r/447)*447;i<r;i++)
		ret += a[i];
	return ret;
}

int32_t main() {
	int N, Q; cin>>N>>Q;
	a.resize(N);
	for (int i=0;i<N;i++) {
		int inp; cin >> inp;
		upd(i,inp);
	}
	for (int i=0;i<Q;i++) {
		int a,b,c;
		cin>>a>>b>>c;
		if (a==1)
			upd(b-1,c);
		else
			cout << qry(c) - qry(b-1) << endl;
	}
	return 0;
}