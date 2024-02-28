import java.io.*;
import java.util.*;

public class RectangleCutting {
	public static void main(String[] args) {
		FastIO io = new FastIO();
		int n=io.nextInt(),m=io.nextInt();
		int dp[][] = new int[n+1][m+1];
		for (int i=1;i<n+1;i++) for (int j=1;j<m+1;j++) dp[i][j]=(int)1e8;
		dp[1][1]=0;
		for (int i=1;i<n+1;i++)
			for (int j=1;j<m+1;j++) {
				if (i==j) dp[i][j]=0;
				else {
					for (int k=1;k<=i;k++)
						dp[i][j]=Math.min(dp[i][j],1+dp[i-k][j]+dp[k][j]);
					for (int k=1;k<=j;k++)
						dp[i][j]=Math.min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
				}
			}
		io.println(dp[n][m]);
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