import java.io.*;
import java.util.*;

public class RoundTrip {
	static boolean vis[];
	static int last[];
	static ArrayList<Integer> adj[];
	static int first, second;
	public static void main(String[] args) {
		FastIO io = new FastIO();
		int n = io.nextInt(), m = io.nextInt();
		adj = new ArrayList[n+1];
		vis = new boolean[n+1];
		last = new int[n+1];
		for (int i=0;i<n+1;i++) adj[i] = new ArrayList<Integer>();
		for (int i=0;i<m;i++) {
			int a=io.nextInt(), b=io.nextInt();
			adj[a].add(b);
			adj[b].add(a);
		}
		for (int i=1;i<n+1;i++)
			if (first==0 && !vis[i]) {
				dfs(i,0);
			}
		if (first==0) {
			io.print("IMPOSSIBLE");
			io.close();
			return;
		}
		ArrayList<Integer> ans = new ArrayList<>();
		ans.add(second);
		int c = first;
		while (c != second) {
			ans.add(c);
			c = last[c];
		}
		ans.add(c);
		io.println(ans.size());
		for (int i : ans) io.print(i+" ");
		io.close();
	}
	static void dfs(int node, int par) {
		vis[node] = true;
		last[node] = par;
		for (int nb : adj[node]) {
			if (vis[nb] && nb != par) {
				first = nb; second = node;
				return;
			} else if (!vis[nb]) 
				dfs(nb,node);
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