import java.io.*;
import java.util.*;

public class CycleFinding {
    public static void main(String[] args) {
        FastIO io = new FastIO();
        int n = io.nextInt(), m = io.nextInt();
        Edge[] edges = new Edge[m];
        for (int i=0;i<m;i++)
            edges[i] = new Edge(io.nextInt(),io.nextInt(),io.nextInt());
        long[] dist = new long[n+1];
        int[] par = new int[n+1];
        for (int i=0;i<n+1;i++)
            dist[i] = Long.MAX_VALUE/2;
        dist[1] = 0;
        for (int i=0;i<n;i++) {
            for (Edge e : edges) {
                if (dist[e.a]+e.w<dist[e.b]) {
                    dist[e.b]=dist[e.a]+e.w;
                    par[e.b]=e.a;
                }
                dist[e.b] = Math.min(dist[e.b],dist[e.a]+e.w);
            }
        }
        int found = 0;
        for (Edge e : edges) {
            if (dist[e.b]>dist[e.a]+e.w) {
                found=e.b;
                break;
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        if (found==0) {
            io.println("NO");
        } else {
            io.println("YES");
            for (int i=0;i<n-1;i++)
                found = par[found];
            ans.add(found);
            do {
                ans.add(par[found]);
                found = par[found];
            } while (found != ans.get(0));
            Collections.reverse(ans);
            for (int i=0;i<ans.size();i++)
                io.print(ans.get(i)+" ");
            io.println();
        }
        io.close();
    }
    static class Edge {
        public int a,b,w;
        public Edge(int x, int y, int z) {
            a=x;b=y;w=z;
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