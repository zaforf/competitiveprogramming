class Segtree {
	public int N=1;
	public long tree[];
	// operator: must be associative and commutative
	public long op(long a, long b) {return Math.max(a,b);}
	public Segtree(int n) {
		while (N < n) N<<=1;
		tree = new long[N<<1];
	}
	// update value at position i to val
	public void upd(int i, long val) {
		i+=N;
		tree[i]=val;
		for (i/=2; i>0; i/=2)
			tree[i] = op(tree[2*i],tree[2*i+1]);
	}
	public long qry(int l, int r) {
		long res=0;
		l += N; r+= N;
		while (l<=r) {
			if (l%2==1) res = op(res,tree[l++]);
			if (r%2==0) res = op(res,tree[r--]);
			l/=2;r/=2;
		}
		return res;
	}
}