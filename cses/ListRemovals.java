import java.io.*;
import java.util.*;

public class ListRemovals {
	public static void main(String[] args) {
		FastIO io = new FastIO();
		int n = io.nextInt();
		Segtree st = new Segtree(n);
		int x[] = new int[n];
		for (int i=0;i<n;i++) {
			x[i] = io.nextInt();
			st.upd(i,1);
		}
		for (int i=0;i<n;i++) {
			int p; p = io.nextInt();
			int c=1,s=0;
			while (c<st.N) { //find first i s.t. sum=p
				if (s+st.tree[2*c]<p) {
					s += st.tree[2*c];
					c = 2*c+1;
				} else
					c = 2*c;
			}
			c-=st.N;
			st.upd(c,0);
			io.print(x[c]+""+(i==n-1?'\n':' '));
		}
		io.close();
	}
	static class Segtree {
		public int N=1;
		public int tree[];
		// operator: must be associative and commutative
		public int op(int a, int b) {return a+b;}
		public Segtree(int n) {
			while (N < n) N<<=1;
			tree = new int[N<<1];
		}
		// update value at position i to val
		public void upd(int i, int val) {
			i+=N;
			tree[i]=val;
			for (i/=2; i>0; i/=2)
				tree[i] = op(tree[2*i],tree[2*i+1]);
		}
		public int qry(int l, int r) {
			int res=0;
			l += N; r+= N;
			while (l<=r) {
				if (l%2==1) res = op(res,tree[l++]);
				if (r%2==0) res = op(res,tree[r--]);
				l/=2;r/=2;
			}
			return res;
		}
	}
}

class FastIO extends PrintWriter {
	private InputStream stream;
	private byte[] buf = new byte[1 << 16];
	private int curChar;
	private int numChars;
	// standard input
	public FastIO() { this(System.in, System.out); }
	public FastIO(InputStream i, OutputStream o) {
		super(o);
		stream = i;
	}
	// file input
	public FastIO(String i, String o) throws IOException {
		super(new FileWriter(o));
		stream = new FileInputStream(i);
	}
	// throws InputMismatchException() if previously detected end of file
	private int nextByte() {
		if (numChars == -1) { throw new InputMismatchException(); }
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) { throw new InputMismatchException(); }
			if (numChars == -1) {
				return -1;  // end of file
			}
		}
		return buf[curChar++];
	}
	// to read in entire lines, replace c <= ' '
	// with a function that checks whether c is a line break
	public String next() {
        int c; do { c = nextByte(); } while (c <= ' ');
        StringBuilder res = new StringBuilder();
        do { res.appendCodePoint(c); c = nextByte(); } while (c > ' ');
        return res.toString();
	}
	public int nextInt() {
        int c; do { c = nextByte(); } while (c <= ' ');
        int sgn = 1; if (c == '-') { sgn = -1; c = nextByte(); }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res = 10*res+c-'0';
            c = nextByte();
        } while (c > ' ');
        return res * sgn;
	}
	public long nextLong() {
        int c; do { c = nextByte(); } while (c <= ' ');
        int sgn = 1; if (c == '-') { sgn = -1; c = nextByte(); }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res = 10*res+c-'0';
            c = nextByte();
        } while (c > ' ');
        return res * sgn;
	}
	public double nextDouble() { return Double.parseDouble(next()); }
}