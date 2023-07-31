#include <bits/stdc++.h>
using namespace std;

int ask(int l,int r) {
	cout<<"? "<<min(l,r)+1<<" "<<max(l,r)+1<<endl;
	int ret; cin>>ret; return --ret;
}

int main() {
	int L=0;
	int R;cin>>R;R--;
	int ind2 = ask(L,R);
	if (ind2!=R && (ind2==0 || ask(L,ind2)!=ind2)) {
		L = ind2;
		while (L+1<R) {
			int m = (L+R)/2;
			if (ask(ind2,m)==ind2)
				R=m;
			else
				L=m;
		}
		cout<<"! "<<R+1<<endl;
	} else {
		R = ind2;
		while (L+1<R) {
			int m = (L+R)/2;
			if (ask(m,ind2)==ind2)
				L=m;
			else
				R=m;
		}
		cout<<"! "<<L+1<<endl;
	}
	return 0;
}