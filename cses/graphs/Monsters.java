import java.io.*;
import java.util.*;

public class Monsters {
	static final int dx[]= {-1,0,1,0}, dy[]= {0,1,0,-1};
	static final char direction[]= {'U','R','D','L'};
	static boolean open[][];
	static ArrayList<Point> monst = new ArrayList<>();
	static Point start;
	static int adist[][], mdist[][];
	static int dir[][];
	static int n,m;
	public static void main(String[] args) throws IOException {
		FastIO io = new FastIO();
		n = io.nextInt(); m = io.nextInt();
		open = new boolean[n][m];
		adist = new int[n][m];
		mdist = new int[n][m];
		dir = new int[n][m];
		for (int i=0;i<n;i++) {
			String s = io.next();
			for (int j=0;j<m;j++) {
				adist[i][j]=-1;
				mdist[i][j]=-1;
				if (s.charAt(j)!='#')
					open[i][j]=true;
				if (s.charAt(j)=='M')
					monst.add(new Point(i,j));
				if (s.charAt(j)=='A')
					start = new Point(i,j);
			}
		}
		bfs(mdist, monst.toArray(new Point[0]));
		bfs(adist, start);
		Point end = null;
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				if (!(i==0 || i==n-1 || j==0 || j==m-1)) continue;
				if (adist[i][j]!=-1 && (adist[i][j] < mdist[i][j] || mdist[i][j]==-1)) {
					end = new Point(i,j);
					break;
				}
			}
			if (end!=null) break;
		}
		if (end==null) {
			io.println("NO");
		} else {
			io.println("YES");
			io.println(adist[end.x][end.y]);
			int currX=end.x,currY=end.y;
			StringBuilder sb = new StringBuilder();
			while (adist[currX][currY]!=0) {
				int currdir = dir[currX][currY];
				sb.append(direction[currdir]);
				currX += dx[(currdir+2)%4];
				currY += dy[(currdir+2)%4];
			}
			sb.reverse();
			io.println(sb);
		}
		io.close();
	}
	static void bfs(int[][] check, Point... args) {
		Queue<Point> q = new LinkedList<>();
		for (Point p : args) {
			check[p.x][p.y]=0;
			q.add(p);
		}
		while (!q.isEmpty()) {
			Point curr = q.peek(); q.remove();
			for (int i=0;i<4;i++) {
				int newX=curr.x+dx[i],newY=curr.y+dy[i];
				if (newX>=0 && newX<n && newY>=0 && newY<m && open[newX][newY] && check[newX][newY]==-1) {
					dir[newX][newY] = i;
					check[newX][newY] = check[curr.x][curr.y]+1;
					q.add(new Point(newX,newY));
				}
			}
		}
	}
	static class Point {
		public int x,y;
		public Point(int a,int b) {
			x=a;y=b;
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