import java.io.*;
import java.util.*;

public class TwoSets2 {
    static final int MOD = 1_000_000_007;
	public static void main(String[] args) throws IOException {
        FastIO io = new FastIO();
        int n=io.nextInt();
        int maxd = n*(n+1)/2;
        long dp[] = new long[maxd+1], ndp[] = new long[maxd+1];
        dp[1]=1;
        // store possibles differences
        // of every combination of two sets
        // for each additional number 1..N
        for (int i=2;i<n+1;i++) {
            for (int j=0;j<maxd+1;j++)
                if (dp[j]>0) {
                    ndp[Math.abs(j-i)]+=dp[j]%MOD;
                    ndp[Math.abs(j-i)]%=MOD;
                    if (j+i<maxd+1) {
                        ndp[j+i]+=dp[j]%MOD;
                        ndp[j+i]%=MOD;
                    }
                }
            dp = ndp.clone();
            Arrays.fill(ndp,0);
        }
        io.print(dp[0]);
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