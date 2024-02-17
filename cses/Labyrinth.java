import java.io.*;
import java.util.*;

public class Labyrinth {
	static final char[] c = {'U', 'L', 'D', 'R'};
	static final int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt();
		Point start = new Point(0,0), end = new Point(0,0);
		boolean open[][] = new boolean[n+2][m+2];
		boolean vis[][] = new boolean[n+2][m+2];
		int dir[][] = new int[n+2][m+2];
		for (int i=0;i<n;i++) {
			String s = sc.next();
			for (int j=0;j<m;j++) {
				if (s.charAt(j) != '#')
					open[i+1][j+1] = true;
				if (s.charAt(j) == 'A')
					start = new Point(i+1,j+1);
				if (s.charAt(j) == 'B')
					end = new Point(i+1,j+1);
			}
		}
		Queue<Point> q = new LinkedList<>();
		q.offer(start); vis[start.x][start.y]=true;
		boolean found = false;
		while (!q.isEmpty()) {
			Point curr = q.poll();
			if (curr.x == end.x && curr.y == end.y) {
				found = true; break;
			}
			for (int i=0;i<4;i++) {
				int newX = curr.x+dx[i], newY = curr.y+dy[i];
				if (open[newX][newY] && !vis[newX][newY]) {
					q.offer(new Point(newX, newY));
					vis[newX][newY]=true;
					dir[newX][newY]=i;
				}
			}
		}
		if (!found) System.out.println("NO");
		else {
			int ptrX = end.x, ptrY = end.y;
			StringBuilder sb = new StringBuilder();
			while (!(ptrX == start.x && ptrY == start.y)) {
				sb.append(c[dir[ptrX][ptrY]]);
				int rev = (dir[ptrX][ptrY]+2)%4;
				ptrX += dx[rev]; ptrY += dy[rev];
			}
			sb.reverse();
			System.out.printf("YES%n%d%n%s%n", sb.length(), sb);
		}
	}
	static class Point {
		public int x,y;
		public Point(int x, int y) {
			this.x=x;
			this.y=y;
		}
		public String toString() {
			return x+" "+y;
		}
	}
}