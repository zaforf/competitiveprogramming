import java.io.*;
import java.util.*;

public class ForestQueries {
	public static void main(String[] args) {
		FastIO io = new FastIO();
		int n = io.nextInt(), q = io.nextInt();
		boolean tree[][] = new boolean[n][n];
		int pfix[][] = new int[n+1][n+1];
		for (int i=0;i<n;i++) {
			String s = io.next();
			for (int j=0;j<n;j++) {
				if (s.charAt(j) == '*') 
					tree[i][j] = true;
				pfix[i+1][j+1] = (tree[i][j]?1:0) + pfix[i][j+1] + pfix[i+1][j] - pfix[i][j];
			}
		}
		for (int i=0;i<q;i++) {
			int y1=io.nextInt(),x1=io.nextInt(),y2=io.nextInt(),x2=io.nextInt();
			io.println(pfix[y2][x2]-pfix[y1-1][x2]-pfix[y2][x1-1]+pfix[y1-1][x1-1]);
		}
		io.close();
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