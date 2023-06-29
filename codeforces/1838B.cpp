#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;cin>>T;
	while (T--) {
		int id1,id2,idn,N;cin>>N;
		for (int i=0;i<N;i++) {
			int p;cin>>p;
			if (p==2) id2=i;
			if (p==1) id1=i;
			if (p==N) idn=i;
		}
		id1++;id2++;idn++;
		if (idn>id1 && idn<id2 || idn>id2 && idn<id1)
			cout<<id1<<" "<<id2;
		else if (idn<min(id1,id2))
			cout<<idn<<" "<<min(id1,id2);
		else
			cout<<max(id1,id2)<<" "<<idn;
		cout<<"\n";
	}
	return 0;
}