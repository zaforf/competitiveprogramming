import java.io.*;
import java.util.*;

public class FlightDiscount {
	static long[] dijk(ArrayList<Pair<Integer,Integer>>[] adj, int node) {
		long dist[] = new long[adj.length];
		Arrays.fill(dist, (long) 1e18); dist[node] = 0;
		PriorityQueue<Pair<Long,Integer>> pq = new PriorityQueue<>(Comparator.comparingLong(x -> x.f));
		pq.add(new Pair(0L,node));
		while (!pq.isEmpty()) {
			Pair<Long, Integer> c = pq.remove();
			if (c.f > dist[c.s]) continue;
			for (Pair<Integer, Integer> nb : adj[c.s]) {
				// in adj, weight is f, nb is s
				if (dist[c.s] + nb.f < dist[nb.s]) {
					dist[nb.s] = dist[c.s] + nb.f;
					pq.add(new Pair(dist[nb.s], nb.s));
				}
			}
		}
		return dist;
	}
	public static void main(String[] args) throws IOException {
		FastIO io = new FastIO();
		int n=io.nextInt(),m=io.nextInt();
		ArrayList<Pair<Integer,Integer>> adj[] = new ArrayList[n+1];
		ArrayList<Pair<Integer,Integer>> badj[] = new ArrayList[n+1];
		ArrayList<Pair<Pair<Integer,Integer>,Integer>> edges = new ArrayList<>();
		for (int i=0;i<n+1;i++) {
			adj[i] = new ArrayList<>();
			badj[i] = new ArrayList<>();
		}
		for (int i=0;i<m;i++) {
			int a=io.nextInt(),b=io.nextInt(),w=io.nextInt();
			adj[a].add(new Pair(w,b));
			badj[b].add(new Pair(w,a));
			edges.add(new Pair(new Pair(a,b),w));
		}
		long dist1[] = dijk(adj,1);
		long distN[] = dijk(badj,n);
		long ans = (long) 1e18;
		for (Pair<Pair<Integer,Integer>,Integer> e : edges) {
			ans = Math.min(ans,dist1[e.f.f]+e.s/2+distN[e.f.s]);
		}
		io.println(ans);
		io.close();
	}
	static class Pair<K, V> {
		public K f;
		public V s;
		public Pair(K a, V b) {
			f=a;s=b;
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