import java.io.*;
import java.util.*;

public class HotelQueries {
	public static void main(String[] args) {
		FastIO io = new FastIO();
		int n = io.nextInt(), m = io.nextInt();
		Segtree st = new Segtree(n);
		for (int i=0;i<n;i++) {
			st.upd(i,io.nextInt());
		}
		for (int i=0;i<m;i++) {
			int x = io.nextInt();
			int l=0,r=n;
			while (l<r) {
				int mid = (r+l)/2;
				if (st.qry(0,mid)>=x)
					r=mid;
				else
					l=mid+1;
			}
			if (r==n) io.print(0+""+(i==m-1?'\n':' '));
			else {
				io.print(l+1+""+(i==m-1?'\n':' '));
				st.upd(l,-x);
			}
		}
		io.close();
	}
	static class Segtree {
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
			tree[i]+=val;
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