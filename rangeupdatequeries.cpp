#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 200000;

// modified segtree where queries become more like updates and vice versa
struct segment_tree{
	int A[4*MAXN];
	int newqry(int x, int l=0, int r=MAXN-1, int v=1){
		if(l > x || r < x) return 0;
		if(l == r)
			return A[v];
		else
			return newqry(x, l, (l+r)/2, v*2)+newqry(x, (l+r)/2+1, r, v*2+1)+A[v];
	}
	void newupd(int ql, int qr, int val, int l=0, int r=MAXN-1, int v=1){
		if(l > qr || r < ql) return;
		if(l >= ql && r <= qr)
			A[v]+=val;
		else {
			newupd(ql, qr, val, l, (l+r)/2, v*2);
			newupd(ql, qr, val, (l+r)/2+1, r, v*2+1);
		}
	}
} S;

int32_t main() {
	int N,Q;cin>>N>>Q;
	for (int i=0;i<N;i++) {
		int inp;cin>>inp;
		S.newupd(i+1,i+1,inp);
	}
	while (Q--) {
		int t;cin>>t;
		if (t==2) {
			int k;cin>>k;
			cout<<S.newqry(k)<<"\n";
		} else {
			int a,b,u;cin>>a>>b>>u;
			S.newupd(a,b,u);
		}
	}
	return 0;
}