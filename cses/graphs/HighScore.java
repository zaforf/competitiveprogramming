import java.io.*;
import java.util.*;

public class HighScore {
	static void dfs(ArrayList<Integer>[] adj, boolean[] vis, int node) {
		for (int nb : adj[node])
			if (!vis[nb]) {
				vis[nb]=true;
				dfs(adj,vis,nb);
			}
	}
	public static void main(String[] args) throws IOException {
		FastIO io = new FastIO();
		int n=io.nextInt(),m=io.nextInt();
		ArrayList<Integer> adj[] = new ArrayList[n+1];
		for (int i=0;i<n+1;i++) adj[i]=new ArrayList<>();
		Edge edges[] = new Edge[m];
		long dist[] = new long[n+1];
		for (int i=0;i<n+1;i++) dist[i]=Long.MIN_VALUE/3;
		dist[1]=0;
		for (int i=0;i<m;i++) {
			int a=io.nextInt(),b=io.nextInt(),w=io.nextInt();
			adj[a].add(b);
			edges[i]=new Edge(a,b,w);
		}
		for (int i=0;i<n-1;i++) {
			for (Edge e : edges) {
				dist[e.to] = Math.max(dist[e.to],dist[e.from]+e.w);
			}
		}
		boolean[][] reach = new boolean[n+1][n+1];
		for (int i=1;i<n+1;i++) {
			reach[i][i]=true;
			dfs(adj,reach[i],i);
		}
		boolean good = true;
		for (Edge e : edges) {
			if (dist[e.from]+e.w>dist[e.to] && reach[1][e.from] && reach[e.from][n]) {
				io.println(-1);
				io.close();
				return;
			}
		}
		io.println(dist[n]);
		io.close();
	}
	static class Edge {
		public int from,to;
		public long w;
		public Edge(int a,int b,long c){
			from=a;
			to=b;
			w=c;
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